/*
Runtime: 8 ms, faster than 84.19% of C++ online submissions for Minimum Path Sum.
Memory Usage: 9.5 MB, less than 99.90% of C++ online submissions for Minimum Path Sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int M = grid.size();
        int N = (grid[0]).size();
        
        for ( int i = 0; i < M; i++ )
        {
            for ( int j = 0; j < N; j++ )
            {
                if ( 0==i && 0==j ) continue;
                if ( 0==i )
                {
                    grid[i][j] += grid[i][j-1];
                }
                else if ( 0==j )
                {
                    grid[i][j] += grid[i-1][j];
                }
                else
                {
                    if ( grid[i-1][j] > grid[i][j-1] )
                    {
                        grid[i][j] += grid[i][j-1];
                    }
                    else
                        grid[i][j] += grid[i-1][j];
                }                
            }
        }
        
        return grid[M-1][N-1];
    }
    
private:
    
    
    
};
