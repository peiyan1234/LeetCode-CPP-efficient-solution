/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 7.8 MB, less than 99.63% of C++ online submissions for Binary Tree Postorder Traversal.
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
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
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
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        if ( root )
        {
        /*
            Postorder
               1. Traverse the left subtree
               2. Traverse the right subtree
               3. Visit the root.
        
        */
            std::stack<TreeNode*> n_stack;
            n_stack.push( root );
            
            while ( !n_stack.empty() )
            {
                TreeNode* p_node = n_stack.top();
                
                const bool right_empty = ( p_node->right == nullptr );
                const bool left_empty  = ( p_node->left  == nullptr );
                
                if ( right_empty && left_empty )
                {
                    ans.push_back( p_node->val );
                    n_stack.pop();
                }
                else
                {
                    if ( !right_empty ) 
                    {
                        n_stack.push( p_node->right );
                        p_node->right = nullptr;
                    }
                    if ( !left_empty  ) 
                    {
                        n_stack.push( p_node->left  );                    
                        p_node->left  = nullptr;
                    }
                }                
            }
            
        }
        
        return ans;
        
    }
};
