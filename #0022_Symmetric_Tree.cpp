/*
https://leetcode.com/problems/symmetric-tree/  
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 
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
    bool isSymmetricTree(TreeNode* p, TreeNode* q) {      
        if (p == nullptr && q != nullptr || p != nullptr && q == nullptr)
            return false;
        if (p == nullptr && q == nullptr || p->val == q->val && isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left))
            return true;
        return false;
    }  
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root || isSymmetricTree(root->left, root->right))
            return true;
        return false;       
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.2 MB, less than 93.33% of C++ online submissions for Symmetric Tree.
*/
