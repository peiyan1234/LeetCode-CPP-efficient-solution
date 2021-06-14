/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.3 MB, less than 80.54% of C++ online submissions for Valid Palindrome.
*/

/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
                
        if ( s.size() > 1 )
        {
            //strcmpi
            int16_t front = 0;
            int16_t back  = s.size() - 1;
            
            while ( back >= front )
            {
                if ( !isalnum( s[front] ) || ' ' == s[front] ) 
                {
                    front++;
                    continue;
                }
                
                if ( !isalnum( s[back] ) || ' ' == s[back] )
                {
                    back--;
                    continue;
                }
                
                if ( tolower(s[back]) != tolower(s[front]) ) return false;
                
                front++;
                back--;
                
            }                
        }
        
        return true;
        
    }
};
