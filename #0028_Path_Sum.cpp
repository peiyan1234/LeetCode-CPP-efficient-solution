/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Example 3:

Input: root = [1,2], targetSum = 0
Output: false
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

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
    bool hasPathSum(TreeNode* const root, int targetSum) {
        
        m_target = &targetSum;
        return hasPathSum( root );
        
    }
    
private:
    
    int* m_target;
    
    bool hasPathSum(TreeNode* const root)
    {
        if ( root )
        {
            if ( root->left == nullptr && root->right == nullptr && root->val == m_target[0] ) return true;   
            
            if ( root->left  ) root->left-> val += root->val;
            if ( root->right ) root->right->val += root->val;
                                
            return ( hasPathSum( root->left ) || hasPathSum( root->right ) );
        }
        
        return false;
    }
 
    
};


/*
Runtime: 4 ms, faster than 98.49% of C++ online submissions for Path Sum.
Memory Usage: 21.1 MB, less than 85.81% of C++ online submissions for Path Sum.
*/
