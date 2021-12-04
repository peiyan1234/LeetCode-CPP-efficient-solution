/*
Runtime: 0 ms Your runtime beats 100.00 % of cpp submissions
Memory Usage: 7.2 MB
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int N = matrix.size();
        if ( 1 == N ) return;
        
        for ( int i = 0; i < N; i++ )
        {
            for ( int j = 0; j < N / 2; j++ )
            {
                swap( matrix[i][j], matrix[i][N-j-1] );
            }
        }
        
        for ( int i = 0; i < N; i++ )
        {
            for ( int j = 0; j < N-i-1; j++ )
            {
                swap( matrix[i][j], matrix[N-j-1][N-i-1] );
            }
        }
    }
};
