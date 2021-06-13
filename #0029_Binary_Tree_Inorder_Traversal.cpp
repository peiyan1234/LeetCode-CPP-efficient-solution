/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 7.9 MB, less than 98.87% of C++ online submissions for Binary Tree Inorder Traversal.
*/

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

*/

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 7.9 MB, less than 98.87% of C++ online submissions for Binary Tree Inorder Traversal.
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
    vector<int> inorderTraversal( TreeNode* root ) {
        
        vector<int> ans;
        
        if ( root )
        {                
            stack<TreeNode*> node_stack;
            node_stack.push( root );
            
            while( !node_stack.empty() )
            {
                TreeNode *&buffer_node = node_stack.top();
                
                if ( buffer_node->left == nullptr && buffer_node->right == nullptr )
                {
                    ans.push_back( buffer_node->val );
                    node_stack.pop();
                    if ( !node_stack.empty() ) node_stack.top()->left = nullptr;
                }
                
                else if ( buffer_node->left == nullptr )
                {
                    ans.push_back( buffer_node->val );
                    node_stack.pop();
                    buffer_node = buffer_node->right;
                    node_stack.push( buffer_node );
                }
                
                else
                {
                    node_stack.push( buffer_node->left );
                }
            }
        }
        
        return ans;
    }
};
