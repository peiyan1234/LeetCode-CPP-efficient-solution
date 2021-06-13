/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.4 MB, less than 86.99% of C++ online submissions for Pascal's Triangle.
*/

/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans( numRows );
        
        int n = 0;
               
        while ( n < numRows )
        {
            if ( n > 1 )
            {
                ans[ n ].resize( n + 1, 1 );
                
                for ( int k = 1; k < n; k++ )
                {
                    ans[ n ][ k ]  = ans[ n - 1][ k - 1 ] + ans[ n - 1 ][ k ];
                }
            }
            else
            {
                ans[ n ].assign( n + 1, 1 );
            }
            
            n++;
        }
        
        return ans;
    }
};
