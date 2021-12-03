/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
Memory Usage: 8.6 MB, less than 12.55% of C++ online submissions for Permutations.
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& input) {
              
        vector<vector<int>> ans;
        if ( 1 == input.size() ) return {{input[0]}};
        
        vector<bool> unused_arr( input.size(), true );
        vector<int> candidate;
        nums = input;
        FindSolutions( ans, nums, unused_arr, candidate );       
        return ans;
    }
    
private:
    
    vector<int> nums;
    
    void FindSolutions( vector<vector<int>>& ans, const vector<int>& nums, 
                        vector<bool> unused_arr, vector<int> candidate )
    {
        if ( nums.size() == candidate.size() )
        {
            ans.push_back(candidate);
            return;
        }
        
        for ( int i = 0; i < nums.size(); i++ )
        {
            if ( unused_arr[i] )
            {
                candidate.push_back( nums[i] );
                unused_arr[i] = false;
                FindSolutions( ans, nums, unused_arr, candidate );
                candidate.pop_back();
                unused_arr[i] = true;
            }
        }
    }
    
};
