/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104 
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
    
    bool isBalanced(TreeNode* root) 
    {
        if (nullptr != root)
        if (check_height(root) == -1) return false; 
        return true;
    }
    
private:  
    
    int check_height(const TreeNode* const root)
    {
        if (nullptr != root)
        {
            int left_h  = check_height(root->left );            
            int right_h = check_height(root->right);
            if (left_h == -1 || right_h == -1) return -1;
            if (abs(left_h - right_h) > 1) return -1;            
            return max(left_h, right_h) + 1;
        }
        return 0;
    }
    
};


/*
Runtime: 4 ms, faster than 98.70% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 20.9 MB, less than 47.24% of C++ online submissions for Balanced Binary Tree.
*/
