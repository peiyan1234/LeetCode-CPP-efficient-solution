/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 10.1 MB, less than 6.22% of C++ online submissions for Invert Binary Tree.
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
    TreeNode* invertTree(TreeNode* root) {
        
        if ( root )
        {
            TreeNode* new_root = new TreeNode( root->val );
            if ( root->left )
            {
                new_root->right = invertTree( root->left );
            }
            if ( root->right )
            {
                new_root->left = invertTree( root->right );
            }
            
            return new_root;
        }
        
        return nullptr;
    }
};
