/*
Runtime: 24 ms, faster than 98.74% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 32.5 MB, less than 44.91% of C++ online submissions for Merge Two Binary Trees.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if ( nullptr == root1 ) return root2;
        if ( nullptr == root2 ) return root1;

        TreeNode* const ans_root = root1;

        stack<TreeNode*> stack_node1;
        stack<TreeNode*> stack_node2;
        stack_node1.push( root1 );
        stack_node2.push( root2 );

        while ( !stack_node1.empty() )
        {   
            TreeNode* tmp1_node = stack_node1.top();
            TreeNode* tmp2_node = (!stack_node2.empty()) ? stack_node2.top() : nullptr ;

            if ( nullptr == tmp2_node ) break;
            printf("(%d, %d) ", tmp1_node->val, tmp2_node->val);

            tmp1_node->val += tmp2_node->val;

            if ( nullptr == tmp1_node->left && nullptr == tmp1_node->right )
            {
                if ( nullptr != tmp2_node->left  ) tmp1_node->left = tmp2_node->left;
                if ( nullptr != tmp2_node->right ) tmp1_node->right = tmp2_node->right;
                stack_node1.pop();
                stack_node2.pop();
            }
            else if ( nullptr == tmp1_node->left && nullptr != tmp1_node->right )
            {
                if ( nullptr != tmp2_node->left ) tmp1_node->left = tmp2_node->left;
                stack_node1.pop();
                stack_node2.pop();
                if ( nullptr != tmp2_node->right ) 
                {
                    stack_node2.push( tmp2_node->right );
                    stack_node1.push( tmp1_node->right );
                }
            }
            else if ( nullptr != tmp1_node->left && nullptr == tmp1_node->right )
            {
                if ( nullptr != tmp2_node->right ) tmp1_node->right = tmp2_node->right;
                stack_node1.pop();
                stack_node2.pop();
                if ( nullptr != tmp2_node->left ) 
                {
                    stack_node2.push( tmp2_node->left );
                    stack_node1.push( tmp1_node->left );
                }
            }
            else
            {
                if ( nullptr == tmp2_node->left && nullptr == tmp2_node->right )
                {
                    stack_node1.pop();
                    stack_node2.pop();
                }
                else if ( nullptr == tmp2_node->left && nullptr != tmp2_node->right )
                {
                    stack_node1.pop();
                    stack_node1.push( tmp1_node->right );
                    stack_node2.pop();
                    stack_node2.push( tmp2_node->right );
                }
                else if ( nullptr != tmp2_node->left && nullptr == tmp2_node->right )
                {
                    stack_node1.pop();
                    stack_node1.push( tmp1_node->left );
                    stack_node2.pop();
                    stack_node2.push( tmp2_node->left );
                }
                else
                {
                    stack_node1.pop();
                    stack_node1.push( tmp1_node->right );
                    stack_node1.push( tmp1_node->left );
                    stack_node2.pop();
                    stack_node2.push( tmp2_node->right );
                    stack_node2.push( tmp2_node->left );
                }
            }

        }

        return ans_root;
    }
};
