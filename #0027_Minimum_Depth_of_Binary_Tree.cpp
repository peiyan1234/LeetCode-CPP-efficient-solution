/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
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

    int minDepth(TreeNode* const root) {
        
        if ( root != nullptr ) 
        {
            climbing_tree( root, 1 );
            
            return m_min_depth;
        }
        
        return 0;
    }
    
private:    
    uint32_t m_min_depth = 1e5;    
    
    void climbing_tree( TreeNode* const node, uint32_t n_node )
    {
        if ( node == nullptr ) return;
        if ( (*node).left == nullptr && (*node).right == nullptr ) 
        {
            if ( n_node < m_min_depth ) m_min_depth = n_node;
            return;
        }
        
        climbing_tree( (*node).left , n_node + 1 );
        climbing_tree( (*node).right, n_node + 1 );
    }

};


/*
Runtime: 212 ms, faster than 91.31% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 144.5 MB, less than 96.81% of C++ online submissions for Minimum Depth of Binary Tree.
*/
