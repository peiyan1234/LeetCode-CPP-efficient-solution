/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
Memory Usage: 7.5 MB, less than 85.03% of C++ online submissions for Unique Paths II.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int M = obstacleGrid.size();
        int N = (obstacleGrid[0]).size();
        if ( 1 == M*N )
        {
            if ( 1 == obstacleGrid[0][0] ) return 0;
            else return 1;
        }
        
        if ( 1 == obstacleGrid[0][0] ) return 0;
        
        for ( int i=0; i<M; i++ )
        {
            for ( int j=0; j<N; j++ )
            {
                if ( 1==obstacleGrid[i][j] )
                    obstacleGrid[i][j] = -1;
            }
        }
        
        obstacleGrid[0][0] = 1;

        for ( int i = 0; i<M; i++ )
        {
            for ( int j = 0; j<N; j++ )
            {
                if ( 0==i && 0==j ) continue;
                if ( -1==obstacleGrid[i][j] )
                {
                    obstacleGrid[i][j] = 0;
                }
                else
                {
                    if ( 0==i )
                    {
                        obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    }
                    else if ( 0==j )
                    {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    }
                    else
                    {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                    }
                }
            }
        }
        
        return obstacleGrid[M-1][N-1];
    }

    
};
