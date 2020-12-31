/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Example 2:

Input: s = " "
Output: 0
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
*/

class Solution {
public:
    int lengthOfLastWord(string input) {
        int scan_index = input.size() - 1;
        unsigned int word_size = 0;
        while (scan_index > -1)
        {         
            switch (input[scan_index])
            {
                case ' ':
                    if (word_size != 0)
                        return word_size;
                    break;
                default:
                    ++word_size;                    
            }
            --scan_index;
        }
        return word_size;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
Memory Usage: 6.7 MB, less than 98.97% of C++ online submissions for Length of Last Word.
*/
