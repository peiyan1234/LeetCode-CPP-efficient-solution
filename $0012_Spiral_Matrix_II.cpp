/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.5 MB, less than 63.32% of C++ online submissions for Spiral Matrix II.
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans;
        
        for ( int i = 0; i < n; i++ )
        {
            vector<int> buf_arr( n, 0 );
            ans.push_back( buf_arr );
        }
        
        int col = 0;
        int row = 0;
        int count = 1;
        const int matrix_size = n * n;
        
        while ( 1 )
        {
            for ( int i = col; i < n-col; i++ )
            {
                ans[row][i] = count;
                count++;
            }
            
            row++;
            if ( matrix_size == count-1 ) break;
            
            for ( int i = row; i <= n-row; i++ )
            {
                ans[i][n-col-1] = count;
                count++;
            }
            
            if ( matrix_size == count-1 ) break;
            
            for ( int i = n-col-2; i >= col; i-- )
            {
                ans[n-row][i] = count;
                count++;
            }
            
            if ( matrix_size == count-1 ) break;
            
            for ( int i = n-row-1; i >= row; i-- )
            {
                ans[i][col] = count;
                count++;
            }
            col++;
            
            if ( matrix_size == count-1 ) break;
        }
        
        return ans;
    }
};
