/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.9 MB, less than 30.13% of C++ online submissions for Spiral Matrix.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int m = matrix.size();             // number of rows
        int n = (matrix[0].size());        // number of columns
        const int matrix_size =  m * n;
        
        int row = 0; 
        int col = 0; 
        
        while ( 1 )
        {
            for ( int i = col; i < n-col; i++ )
            {
                ans.push_back( matrix[row][i] );
                printf( "%d ", ans[ ans.size()-1 ] );
            }
            
            row++;
            if ( ans.size() == matrix_size ) break;
            
            for ( int i = row; i <= m-row; i++ )
            {
                ans.push_back( matrix[i][n-col-1] );
            }
            
            if ( ans.size() == matrix_size ) break;
            
            for ( int i = n-col-2; i >= col; i-- )
            {
                ans.push_back( matrix[m-row][i] );
            }
            
            if ( ans.size() == matrix_size ) break;
            
            for ( int i = m-row-1; i >= row; i-- )
            {
                ans.push_back( matrix[i][col] );
            }
            col++;
            
            if ( ans.size() == matrix_size ) break;
        }       
        
        return ans;
    }
};
