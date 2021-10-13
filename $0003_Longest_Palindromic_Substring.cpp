/*
Runtime: 12 ms, faster than 93.77% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 9.1 MB, less than 63.02% of C++ online submissions for Longest Palindromic Substring.

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

class Solution {
public:
    string longestPalindrome(const string &s) 
    {
        if ( 1 == s.size() ) return s;
        
        string m_s;        
        m_s.push_back('_');        
        for ( int i = 0; i < s.size(); i++ )
        {
            m_s.push_back( s[i] );
            m_s.push_back( '_' );
        }
        
        vector<int> radii( m_s.size(), -1 );
        int t_center = 0;
        int max_r    = 0;
        
        int k = 0;
        while ( k < m_s.size() )
        {
            int r = 1;
            while ( k-r >= 0 && k+r < m_s.size() )
            {
                if ( m_s[ k-r ] == m_s[ k+r] ) r++;
                else
                    break;
            }
            
            radii[k] = r-1;
                        
            const int &R = radii[k];
            
            if ( R > max_r ) 
            {
                max_r = R;
                t_center = k;
            }
            
            if ( R > 0 )
            for ( int i = 1; i <= R; i++ )
            {
                if ( radii[ k-i ] < R-i ) radii[ k+i ] = radii[ k-i ];
                else if ( radii[ k-i ] > R-i ) radii[ k+i ] = R-i;
                else
                {
                    int r = R-i+1;
                    while ( k+i-r >= 0 && k+i+r < m_s.size() )
                    {
                        if ( m_s[ k+i-r ] == m_s[ k+i+r ] ) r++;
                        else
                            break;
                    }
                    
                    radii[ k+i ] = r-1;
                    
                    const int &radius = radii[ k+i ];
                    
                    if ( radius > max_r ) 
                    {
                        max_r = radius;
                        t_center = k+i;
                    }
                }
            }
                       
            k += R+1;
        }
        
        string ans_s;        
        
        for ( int i = t_center - radii[ t_center ]; i <= t_center + radii[ t_center ]; i++ )
        {
            if ( '_' != m_s[i] ) 
                ans_s.push_back( m_s[i] );
        }
        
        return ans_s;
    }
};
