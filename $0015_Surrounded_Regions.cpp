/*
Runtime: 12 ms, faster than 78.35% of C++ online submissions for Surrounded Regions.
Memory Usage: 10.8 MB, less than 19.80% of C++ online submissions for Surrounded Regions.
*/

class Solution {
public:
    void solve( vector<vector<char>>& board ) {
        
        const int ROWS = board.size();
        const int COLS = (board[0]).size();
        if ( 1 == ROWS && 1 == COLS ) return;
        
        unordered_map< char*, vector<int> > boundary;
        stack< char* > boundary_O;
        
        for ( int i = 0; i < ROWS; i++ )
        {
            if ( 0 == i || i == ROWS-1 )
            {
                for ( int j = 0; j < COLS; j++ )
                {
                    char* ptr = &(board[i][j]);
                    if ( 'O' == *ptr ) boundary_O.push( ptr );
                    boundary[ptr] = { i, j };
                }
            }
            else
            {
                char* ptr_r = &(board[i][0]);
                char* ptr_l = &(board[i][COLS-1]);
                if ( 'O' == *ptr_r ) boundary_O.push( ptr_r );
                if ( 'O' == *ptr_l ) boundary_O.push( ptr_l );
                boundary[ptr_r] = { i, 0 };
                boundary[ptr_l] = { i, COLS-1 };
            }
        }
        
        while ( !boundary_O.empty() )
        {
            const vector<int>& coords = boundary[ boundary_O.top() ];
            boundary_O.pop();
            
            if ( ROWS > coords[0]+1 )
            {
                if (  'O' == board[coords[0]+1][coords[1]]  
                   && boundary.end() == boundary.find( &(board[coords[0]+1][coords[1]]) ) )
                {
                    boundary[&(board[coords[0]+1][coords[1]])] = { coords[0]+1, coords[1] };
                    boundary_O.push( &(board[coords[0]+1][coords[1]]) );
                }
            }
            
            if ( 0 <= coords[0]-1 )
            {
                if (  'O' == board[coords[0]-1][coords[1]]  
                   && boundary.end() == boundary.find( &(board[coords[0]-1][coords[1]]) ) )
                {
                    boundary[&(board[coords[0]-1][coords[1]])] = { coords[0]-1, coords[1] };
                    boundary_O.push( &(board[coords[0]-1][coords[1]]) );
                }
            }
                     
            if ( COLS > coords[1]+1 )
            {
                if ( 'O' == board[coords[0]][coords[1]+1]
                   && boundary.end() == boundary.find( &(board[coords[0]][coords[1]+1]) ) )
                {
                    boundary[&(board[coords[0]][coords[1]+1])] = { coords[0], coords[1]+1 };
                    boundary_O.push( &(board[coords[0]][coords[1]+1]) );
                }
            }
              
            if ( 0 <= coords[1]-1 )
            {
                if ( 'O' == board[coords[0]][coords[1]-1]
                   && boundary.end() == boundary.find( &(board[coords[0]][coords[1]-1]) ) )
                {
                    boundary[&(board[coords[0]][coords[1]-1])] = { coords[0], coords[1]-1 };
                    boundary_O.push( &(board[coords[0]][coords[1]-1]) );
                }
            }
        }
        
        for ( int i = 0; i < ROWS; i++ )
        {
            for ( int j = 0; j < COLS; j++ )
            {
                if ( 'O' == board[i][j]
                   && boundary.end() == boundary.find(&(board[i][j])) ) 
                    board[i][j] = 'X';
            }
        }
        
    }
    
};
