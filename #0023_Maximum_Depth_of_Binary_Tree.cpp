/* 
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
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
    void treewalker(TreeNode* T)
    {
        if (nullptr != T)
        {
            if (nullptr != T->left && nullptr != T->right)
            {
                T->left->val = 1 + T->val;
                T->right->val = 1 + T->val;
                treewalker(T->left);
                treewalker(T->right);
            }
            else if (nullptr == T->left && nullptr != T->right)
            {
                T->right->val = 1 + T->val;
                treewalker(T->right);
            }
            else if (nullptr != T->left && nullptr == T->right)
            {
                T->left->val = 1 + T->val;
                treewalker(T->left);
            }
            else if (T->val > depth)
                depth = T->val;
        }
    }
    
    int maxDepth(TreeNode* root) {
        if (nullptr != root) {
            root->val = 1;
            treewalker(root);
        }
        return depth;
    }
private:
    int depth = 0;
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.8 MB, less than 93.69% of C++ online submissions for Maximum Depth of Binary Tree.
*/
