/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.2 MB, less than 86.74% of C++ online submissions for Pascal's Triangle II.
*/

/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans( rowIndex + 1, 1 );
        
        unsigned long numerator   = rowIndex;
        
        for ( int k = 1; k < ( ans.size() + 1 ) / 2; k++ )
        {
            
            numerator /= k;
            
            ans[ k ] = numerator;
                        
            ans[ ans.size() - k - 1 ] = ans[ k ];
            
            numerator *= rowIndex - k;
        }
        
        return ans;
        
    }
};
