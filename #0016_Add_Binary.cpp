/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string Ans = "";
        unsigned int _index_ = 0;
        char buffer = '0';
        while (_index_ < max(a.size(), b.size()))
        {
            switch (buffer)
            {
                case '0':
                    if (_index_ < a.size())
                    {
                        if (_index_ < b.size())
                        {
                            switch (bitset<1>(a[_index_]).count() + bitset<1>(b[_index_]).count())
                            {
                                case 0:
                                    Ans.push_back('0');
                                    break;
                                case 1:
                                    Ans.push_back('1');
                                    break;
                                case 2:
                                    Ans.push_back('0');
                                    buffer = '1';
                                    break;
                            }
                        }
                        else
                        {
                            switch (bitset<1>(a[_index_]).count())
                            {
                                case 0:
                                    Ans.push_back('0');
                                    break;
                                case 1:
                                    Ans.push_back('1');
                                    break;
                            }
                        }
                    }
                    else
                    {
                        switch (bitset<1>(b[_index_]).count())
                        {
                            case 0:
                                Ans.push_back('0');
                                break;
                            case 1:
                                Ans.push_back('1');
                                break; 
                        }
                    }
                    break;
                case '1':
                    if (_index_ < a.size())
                    {
                        if (_index_ < b.size())
                        {
                            switch (bitset<1>(a[_index_]).count() + bitset<1>(b[_index_]).count())
                            {
                                case 0:
                                    Ans.push_back('1');
                                    buffer = '0';
                                    break;
                                case 1:
                                    Ans.push_back('0');
                                    break;
                                case 2:
                                    Ans.push_back('1');
                                    break;
                            }
                        }
                        else
                        {
                            switch (bitset<1>(a[_index_]).count())
                            {
                                case 0:
                                    Ans.push_back('1');
                                    buffer = '0';
                                    break;
                                case 1:
                                    Ans.push_back('0');
                                    break;
                            }
                        }
                    }
                    else
                    {
                        switch (bitset<1>(b[_index_]).count())
                        {
                            case 0:
                                Ans.push_back('1');
                                buffer = '0';
                                break;
                            case 1:
                                Ans.push_back('0');
                                break;
                        }
                    }
                    break;
            }
            ++_index_;
        }
        if (buffer == '1')
            Ans.push_back('1');

        reverse(Ans.begin(), Ans.end());
        return Ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.
Memory Usage: 6.5 MB, less than 95.18% of C++ online submissions for Add Binary.
*/
