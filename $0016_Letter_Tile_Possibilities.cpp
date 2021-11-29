/*
Runtime: 4 ms, faster than 94.86% of C++ online submissions for Letter Tile Possibilities.
Memory Usage: 6 MB, less than 88.41% of C++ online submissions for Letter Tile Possibilities.
*/

class Solution {
public:
    int numTilePossibilities(string tiles) 
    {
        if ( 1 == tiles.size() ) return 1;
                
        int char_count_arr[26] {};
        for ( int i = 0; i < tiles.size(); i++ )
            char_count_arr[ tiles[i] - 'A' ]++;
        
        int ans = 0;
        findsolutions( ans, char_count_arr );
        return ans;
    }
private:
    
    void findsolutions( int& ans, int char_count_arr[26] )
    {
        for ( int i = 0; i < 26; i++ )
        {
            if ( 0 != char_count_arr[i] )
            {
                char_count_arr[i]--;
                ans++;
                findsolutions( ans, char_count_arr );
                char_count_arr[i]++;  
            }              
        }
    }
};


    
