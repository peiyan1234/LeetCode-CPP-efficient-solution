/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 8.4 MB, less than 5.38% of C++ online submissions for Letter Combinations of a Phone Number.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if ( 0 == digits.size() ) return {};
        vector<string> ans;
        len = digits.size();
        
        queue<char> char_arr;
        for ( int i = 0; i < digits.size(); i++ )
        {
            char_arr.push( digits[i] );
        }
        
        string buf;
        FindSolutions( ans, char_arr, buf );
        
        return ans;
    }

private:
    
    int len = 0;
    unordered_map<char, string> digit2letter_map = {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        };
    
    void FindSolutions( vector<string>& ans, queue<char> char_arr, string& buf )
    {
        if ( len == buf.size() ) ans.push_back( buf );
        while ( !char_arr.empty() )
        {
            const string& letters = digit2letter_map[ char_arr.front() ];
            char_arr.pop();
            for ( int i = 0; i < letters.size(); i++ )
            {
                buf.push_back( letters[i] );
                FindSolutions( ans, char_arr, buf );
                buf.pop_back();
            }
        }
    }
    
};
