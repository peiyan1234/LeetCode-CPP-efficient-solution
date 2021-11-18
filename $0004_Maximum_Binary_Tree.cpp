/*
Runtime: 72 ms, faster than 83.70% of C++ online submissions for Maximum Binary Tree.
Memory Usage: 42.2 MB, less than 68.87% of C++ online submissions for Maximum Binary Tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode* const root = new TreeNode( 0 );
        
        build_tree( root, nums, 0, nums.size() );
        
        return root;
    }
    
private:
    
    void get_max( const vector<int>& nums, 
                       int&         index,
                 const int&         start,
                 const int&         end   )
    {
        for ( int i = start; i < end; i++ )
        {
            if ( nums[index] < nums[i] ) 
            { 
                index = i;
            }
        }       
    }
    
    void build_tree( TreeNode* const node, const vector<int>& nums,
                     const int& start, const int& end)
    {
        if ( end-start > 0 )
        {
            int index = start;
            get_max( nums, index, start, end );
            node->val = nums[index];
            
            if ( index > start )
            {
                TreeNode* new_left = new TreeNode();
                node->left = new_left;
                build_tree( node->left, nums, start, index );
            }

            if ( index < end-1 )
            {
                TreeNode* new_right = new TreeNode();
                node->right = new_right;
                build_tree( node->right, nums, index+1, end );
            }
        }
    }
    
};
