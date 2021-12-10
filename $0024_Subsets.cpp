/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
Memory Usage: 7.8 MB, less than 28.87% of C++ online submissions for Subsets.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> buf;
        for ( int i = 0; i <= nums.size(); i++ )
        {            
            FindSolutions( ans, nums, i, 0, buf );
        }
        
        return ans;
    }

    void FindSolutions( vector<vector<int>>& ans, const vector<int>& nums, 
                        const int& k, const int& t, vector<int> buf )
    {
        if ( 0 == k )
        {
            ans.push_back({});
            return;
        }
        
        if ( buf.size() == k )
        {
            ans.push_back(buf);
            return;
        }
        
        for ( int i = t; i < nums.size(); i++ )
        {
            buf.push_back( nums[i] );
            FindSolutions( ans, nums, k, i+1, buf );
            buf.pop_back();
        }
    }
    
};
