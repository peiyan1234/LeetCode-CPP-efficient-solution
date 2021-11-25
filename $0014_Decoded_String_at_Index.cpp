/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decoded String at Index.
Memory Usage: 6.3 MB, less than 20.65% of C++ online submissions for Decoded String at Index.
*/

#include <ctype.h>

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        string ans;
        
        if ( 1 == k ) ans.push_back( s[0] );
        else
        {
            int count = 0;
            char last_char = '\0';
            for ( int i = 0; i < s.size(); i++ )
            {
                const char& c = s[i];
                if ( isdigit(c) )
                {
                    if ( count > k/(c-'0') )
                    {
                        const int new_k = k % count;
                        if ( new_k == 0 )
                        {
                            if ( '\0' == last_char ) break;
                            ans.push_back(last_char);
                            break;
                        }
                        else
                        {
                            return decodeAtIndex( s.substr(0, i+1), new_k );
                        }
                    }
                    else 
                    {
                        count *= ( c-'0' );
                        if ( count == k ) 
                        {
                            if ( '\0' == last_char ) break;
                            ans.push_back(last_char);
                            break;
                        }
                    }
                }
                else
                {
                    last_char = s[i];
                    count++; 
                    if ( count == k ) 
                    {
                        ans.push_back(last_char);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
