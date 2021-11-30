/*
Runtime: 8 ms, faster than 99.84% of C++ online submissions for Valid Sudoku.
Memory Usage: 18.5 MB, less than 61.16% of C++ online submissions for Valid Sudoku.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool ans = true;
        
        RULE_1( ans, board );
        if ( !ans ) return false;
        RULE_2( ans, board );
        if ( !ans ) return false;
        RULE_3( ans, board );
        if ( !ans ) return false;
        
        return true;
    }

private:
    
    void RULE_1( bool& ans, const vector<vector<char>>& board )
    {
        for ( int i = 0; i < 9; i++ )
        {
            int count[9] = {};
            for ( int j = 0; j < 9; j++ )
            {
                const char& c = board[j][i];
                if ( '.' != c ) 
                {
                    count[ c-'1' ]++;
                    if ( 1 < count[ c-'1'] )
                    {
                        ans = false;
                        return;
                    }
                }
                
            }
        }
    }
    
    void RULE_2( bool& ans, const vector<vector<char>>& board )
    {
        for ( int i = 0; i < 9; i++ )
        {
            int count[9] = {};
            for ( int j = 0; j < 9; j++ )
            {
                const char& c = board[i][j];
                if ( '.' != c ) 
                {
                    count[ c-'1' ]++;
                    if ( 1 < count[ c-'1'] )
                    {
                        ans = false;
                        return;
                    }
                }
                
            }
        }
    }
    
    void RULE_3( bool& ans, const vector<vector<char>>& board )
    {
        vector<vector<int>> starts;
        for ( int i = 0; i < 9; i+=3 )
        {
            for ( int j = 0; j < 9; j+=3 )
            {
                starts.push_back( {i, j} );
            }
        }
        
        for ( auto start : starts )
        {
            int count[9] = {};
            for ( int m = start[0]; m < start[0]+3; m++ )
            {
                for ( int n = start[1]; n < start[1]+3; n++ )
                {
                    const char& c = board[m][n];
                    if ( '.' != c ) 
                    {
                        count[ c-'1' ]++;
                        if ( 1 < count[ c-'1'] )
                        {
                            ans = false;
                            return;
                        }
                    }  
                }
            }
        }
        
    }

};
