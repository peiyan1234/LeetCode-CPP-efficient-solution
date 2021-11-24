/*
Runtime: 8 ms, faster than 98.40% of C++ online submissions for Spiral Matrix III.
Memory Usage: 12.2 MB, less than 62.57% of C++ online submissions for Spiral Matrix III.
*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(const int rows, 
                                        const int cols, 
                                        const int rStart, 
                                        const int cStart) 
    {        
        const int SIZE = rows * cols;
        
        if ( 0 == SIZE ) return {};
        if ( 1 == SIZE ) 
        {
            return { {0, 0} };
        }
        
        vector<vector<int>> ans;
        
        int count = 1;
        int r = rStart;
        int c = cStart;
        int step = 2;
        ans.push_back( {r, c} );
        
        while (1)
        {
            for ( int i = c; i < c+step; i++ )
            {
                if (  0 <= i && i < cols 
                   && 0 <= r && r < rows )
                {
                    if ( i==c ) continue;
                    else
                    {
                        ans.push_back( {r, i} );
                        count++;
                    }
                }
            }
            
            if ( count >= SIZE ) break;
            c += step-1;
            
            for ( int i = r; i < r+step; i++ )
            {
                if (  0 <= i && i < rows 
                   && 0 <= c && c < cols )
                {
                    if ( i==r ) continue;
                    else
                    {
                        ans.push_back( {i, c} );
                        count++;
                    }
                }
            }
            
            if ( count >= SIZE ) break;
            r += step-1;
            step++;
            
            for ( int i = c; i > c-step; i-- )
            {
                if (  0 <= i && i < cols 
                   && 0 <= r && r < rows )
                {
                    if ( i==c ) continue;
                    else
                    {
                        ans.push_back( {r, i} );
                        count++;
                    }
                }
            }
            
            if ( count >= SIZE ) break;
            c += 1-step;
            
            for ( int i = r; i > r-step; i-- )
            {
                if (  0 <= i && i < rows 
                   && 0 <= c && c < cols )
                {
                    if ( i==r ) continue;
                    else
                    {
                        ans.push_back( {i, c} );
                        count++;
                    }
                }
            }
            
            if ( count >= SIZE ) break;
            r += 1-step;
            step++;
        }
                
        return ans;      
    }
};
