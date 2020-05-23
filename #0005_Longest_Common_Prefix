/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        short array_size = strs.size();
        if (array_size == 0)
            return "";
        short min_str_len = strs[0].size();
        for (short x = 0; x < array_size; ++x)
            if (min_str_len > strs[x].size())
                min_str_len = strs[x].size();
        
        bool checker = true;
        short x = 0;
        while (x < min_str_len)
        {
            for (short y = 0; y < array_size; ++y)
            {
                if (strs[0][x] != strs[y][x])
                {
                    checker = false;
                    break;
                }
            }
            if (checker == false)
                break;
            ++x;
        }

        return strs[0].substr(0, x);
    }
};


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.3 MB, less than 6.45% of C++ online submissions for Longest Common Prefix.
*/
