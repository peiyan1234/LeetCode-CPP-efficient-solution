/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
Memory Usage: 12 MB, less than 98.92% of C++ online submissions for Binary Tree Paths.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        if ( nullptr == root ) return ans;
        
        stack<TreeNode*> node_stack;
        node_stack.push( root );
        
        stack<string> ans_stack;
        
        while ( !node_stack.empty() )
        {
            const TreeNode* const node = node_stack.top();
            if ( 0 == ans.size() )
            {
                string str = to_string( node->val );
                ans.push_back( str );
                node_stack.pop();
            }
            else
            {
                string str = to_string( node->val );
                ans[ ans.size()-1 ] = ans[ ans.size()-1 ] + "->" + str;
                node_stack.pop();
            }
            
            if ( nullptr == node->left && nullptr == node->right )
            {
                if ( !ans_stack.empty() )
                {
                    ans.push_back( ans_stack.top() );
                    ans_stack.pop();
                }
            }
            else if ( nullptr == node->left && nullptr != node->right )
            {
                node_stack.push( node->right );
            }
            else if ( nullptr != node->left && nullptr == node->right )
            {
                node_stack.push( node->left );
            }
            else
            {
                node_stack.push( node->right );
                node_stack.push( node->left  );
                ans_stack.push( ans.back() );
            }
            
        }
        
        return ans;
        
    }
};
