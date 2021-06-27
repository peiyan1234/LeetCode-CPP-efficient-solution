/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.4 MB, less than 41.67% of C++ online submissions for Binary Tree Preorder Traversal.
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

/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [1,2]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        if ( root )
        {
            
            /*
               Pre-order:            
                   1. Visit the root.
                   2. Traverse the left subtree, 
                   3. Traverse the right subtree
            
            */
            
            TreeNode* p_node = root;
            std::stack<TreeNode*> n_stack;
            
            while ( p_node || !n_stack.empty() )
            {
                if ( p_node )
                {
                    ans.push_back( p_node->val );
                    if ( p_node -> right ) n_stack.push( p_node->right );
                    if ( p_node -> left  ) p_node = p_node -> left;
                    else                   p_node = nullptr;
                }
                else
                {
                    p_node = n_stack.top();
                    n_stack.pop();
                }
            }
        }
        
        return ans;
        
    }
};
