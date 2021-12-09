/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.5 MB, less than 51.16% of C++ online submissions for Search a 2D Matrix.
*/

class Solution {
public:
    bool searchMatrix( vector<vector<int>>& matrix, int target ) 
    {
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        if ( 1==M*N )
        {
            if ( target == matrix[0][0] ) return true;
            else return false;
        }
        
        int n = 0;
        int i = M / 2;
        int upp = M;
        int low = 0;
        while (1)
        {
            if ( 1 == upp-low )
            {
                if ( upp < M )
                if ( target == matrix[upp][N-1] ) return true;
                if ( target == matrix[low][N-1] ) return true;
                if ( matrix[low][N-1] < target && upp < M ) n = upp;
                else n = low;
                break;
            }
            if ( target == matrix[i][N-1] ) return true;
            if ( target > matrix[i][N-1] )
            {
                low = i;
                i = ( low + upp ) / 2;
            }
            else
            {
                upp = i;
                i = ( low + upp ) / 2;
            }
        }
        
        i = N / 2;
        upp = N;
        low = 0;
        while (1)
        {
            if ( 1 == upp-low )
            {
                if ( upp < N )
                if ( target == matrix[n][upp] ) return true;
                if ( target == matrix[n][low] ) return true;
                break;
            }
            if ( target == matrix[n][i] ) return true;
            if ( target > matrix[n][i] )
            {
                low = i;
                i = ( low + upp ) / 2;
            }
            else
            {
                upp = i;
                i = ( low + upp ) / 2;
            }
        }
        
        return false;
    }
};
