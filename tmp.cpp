#include <vector>
#include <stdexcept>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <array>
#include <algorithm>
#include <cstring>
#include <memory>

// Define AAD (Additional Authenticated Data) as a macro
#define AES_GCM_AAD "MyAuthenticatedData"
constexpr size_t AES_GCM_AAD_LEN = sizeof(AES_GCM_AAD) - 1;

using key_type = std::array<unsigned char, 32>;  // AES-256 key size
using nonce_type = std::array<unsigned char, 12>;  // AES-GCM nonce size

// Generate a random key for AES encryption
key_type generate_key() {
    key_type key;
    if (RAND_priv_bytes(key.data(), key.size()) != 1) {
        throw std::runtime_error("Failed to generate secure random key.");
    }
    return key;
}

// Generate a random nonce for AES-GCM
nonce_type generate_nonce() {
    nonce_type nonce;
    if (RAND_priv_bytes(nonce.data(), nonce.size()) != 1) {
        throw std::runtime_error("Failed to generate secure random nonce.");
    }
    return nonce;
}

// Encrypt data using AES-GCM
void encrypt_aes_gcm(const unsigned char* plaintext, int plaintext_len,
                     const key_type& key, const nonce_type& nonce,
                     const unsigned char* aad, int aad_len,
                     std::vector<unsigned char>& ciphertext,
                     std::vector<unsigned char>& tag) {
    auto ctx = std::unique_ptr<EVP_CIPHER_CTX, decltype(&EVP_CIPHER_CTX_free)>(
        EVP_CIPHER_CTX_new(), &EVP_CIPHER_CTX_free);
    
    if (!ctx) throw std::runtime_error("Failed to create EVP_CIPHER_CTX.");

    if (EVP_EncryptInit_ex(ctx.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1 ||
        EVP_CIPHER_CTX_ctrl(ctx.get(), EVP_CTRL_GCM_SET_IVLEN, nonce.size(), nullptr) != 1 ||
        EVP_EncryptInit_ex(ctx.get(), nullptr, nullptr, key.data(), nonce.data()) != 1) {
        throw std::runtime_error("Failed to initialize AES-GCM encryption.");
    }

    if (aad && aad_len > 0) {
        int len;
        if (EVP_EncryptUpdate(ctx.get(), nullptr, &len, aad, aad_len) != 1) {
            throw std::runtime_error("Failed to process AAD.");
        }
    }

    ciphertext.resize(plaintext_len + EVP_CIPHER_block_size(EVP_CIPHER_CTX_cipher(ctx.get())));

    int len;
    if (EVP_EncryptUpdate(ctx.get(), ciphertext.data(), &len, plaintext, plaintext_len) != 1) {
        throw std::runtime_error("Failed to encrypt data.");
    }
    int ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx.get(), ciphertext.data() + len, &len) != 1) {
        throw std::runtime_error("Failed to finalize encryption.");
    }
    ciphertext_len += len;
    ciphertext.resize(ciphertext_len);

    tag.resize(16);
    if (EVP_CIPHER_CTX_ctrl(ctx.get(), EVP_CTRL_GCM_GET_TAG, tag.size(), tag.data()) != 1) {
        throw std::runtime_error("Failed to retrieve GCM tag.");
    }
}

// Decrypt data using AES-GCM
bool decrypt_aes_gcm(const std::vector<unsigned char>& ciphertext,
                     const key_type& key, const nonce_type& nonce,
                     const unsigned char* aad, int aad_len,
                     const std::vector<unsigned char>& tag,
                     std::vector<unsigned char>& plaintext) {
    auto ctx = std::unique_ptr<EVP_CIPHER_CTX, decltype(&EVP_CIPHER_CTX_free)>(
        EVP_CIPHER_CTX_new(), &EVP_CIPHER_CTX_free);

    if (!ctx) throw std::runtime_error("Failed to create EVP_CIPHER_CTX.");

    if (EVP_DecryptInit_ex(ctx.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1 ||
        EVP_CIPHER_CTX_ctrl(ctx.get(), EVP_CTRL_GCM_SET_IVLEN, nonce.size(), nullptr) != 1 ||
        EVP_DecryptInit_ex(ctx.get(), nullptr, nullptr, key.data(), nonce.data()) != 1) {
        return false;
    }

    if (aad && aad_len > 0) {
        int len;
        if (EVP_DecryptUpdate(ctx.get(), nullptr, &len, aad, aad_len) != 1) {
            return false;
        }
    }

    plaintext.resize(ciphertext.size());

    int len;
    if (EVP_DecryptUpdate(ctx.get(), plaintext.data(), &len, ciphertext.data(), ciphertext.size()) != 1) {
        return false;
    }
    int plaintext_len = len;

    if (EVP_CIPHER_CTX_ctrl(ctx.get(), EVP_CTRL_GCM_SET_TAG, tag.size(), const_cast<unsigned char*>(tag.data())) != 1) {
        return false;
    }

    if (EVP_DecryptFinal_ex(ctx.get(), plaintext.data() + len, &len) != 1) {
        return false;
    }
    plaintext_len += len;

    plaintext.resize(plaintext_len);
    return true;
}

// Obfuscator class template
template <size_t N>
class obfuscator {
public:
    consteval obfuscator(const char (&data)[N]);
    ~obfuscator();

    bool decrypt(std::vector<unsigned char>& out_data) const;
    const char* operator()() const;

private:
    std::vector<unsigned char> m_ciphertext;
    std::vector<unsigned char> m_tag;
    key_type m_key;
    nonce_type m_nonce;

    void encrypt(const char (&data)[N]);
};

template <size_t N>
consteval obfuscator<N>::obfuscator(const char (&data)[N])
    : m_ciphertext{}, m_tag{}, m_key(generate_key()), m_nonce(generate_nonce()) {
    encrypt(data);
}

template <size_t N>
obfuscator<N>::~obfuscator() {
    m_ciphertext.clear();
    m_tag.clear();
    m_key.fill(0);
    m_nonce.fill(0);
}

template <size_t N>
void obfuscator<N>::encrypt(const char (&data)[N]) {
    encrypt_aes_gcm(reinterpret_cast<const unsigned char*>(data), N, m_key, m_nonce,
                    reinterpret_cast<const unsigned char*>(AES_GCM_AAD), AES_GCM_AAD_LEN,
                    m_ciphertext, m_tag);
}

template <size_t N>
bool obfuscator<N>::decrypt(std::vector<unsigned char>& out_data) const {
    return decrypt_aes_gcm(m_ciphertext, m_key, m_nonce,
                           reinterpret_cast<const unsigned char*>(AES_GCM_AAD), AES_GCM_AAD_LEN,
                           m_tag, out_data);
}

template <size_t N>
const char* obfuscator<N>::operator()() const {
    static thread_local std::string decrypted_data(N, '\0');
    std::vector<unsigned char> out_data;
    if (!decrypt(out_data)) {
        throw std::runtime_error("Decryption failed.");
    }
    std::copy(out_data.begin(), out_data.end(), decrypted_data.begin());
    return decrypted_data.c_str();
}

// Factory function for creating obfuscator instances
template <size_t N>
consteval obfuscator<N> make_obfuscator(const char (&data)[N]) {
    return obfuscator<N>(data);
}

// Secure string obfuscation macro
#define AY_OBFUSCATE(data) ([]() -> const char* { \
    static thread_local auto obf = make_obfuscator(data); \
    return obf(); \
}())
