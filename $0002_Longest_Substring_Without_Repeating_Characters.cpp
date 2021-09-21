/*
Runtime: 8 ms, faster than 85.42% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.3 MB, less than 73.18% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        
        int max = 0;
        if ( s.size() != 0 )
        {          
            int s0  = 0;            
            unordered_map<char, int> u_map;
            
            for ( int i = 0; i < s.size(); i++ )
            {   
                s0 = ( u_map.find( s[i] ) != u_map.end() && u_map[ s[i] ] >= s0 ) 
                     ? u_map[ s[i] ] + 1 : s0;
                
                u_map[ s[i] ] = i;
                
                const int len = i - s0 + 1;
                max = ( len > max ) ? len : max;
            }
        }      
        
        return max;
    }
};
