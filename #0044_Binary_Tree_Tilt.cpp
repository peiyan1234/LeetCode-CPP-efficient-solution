/*
Runtime: 12 ms, faster than 94.13% of C++ online submissions for Binary Tree Tilt.
Memory Usage: 24.4 MB, less than 7.04% of C++ online submissions for Binary Tree Tilt.
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
    int findTilt(TreeNode* root) {
        
        if ( nullptr == root ) return 0;
        
        go_through_nodes( root );
        int sum = 0;
        
        for ( int i = 0; i < arr.size(); i++ )
        {
            sum += arr[i];
        }
        
        return sum;
    }
    
private:
    
    vector<int> arr;
    
    void go_through_nodes( TreeNode* node )
    {
        if ( nullptr == node->left && nullptr == node->right )
        {
            return;
        }
        else if ( nullptr == node->left && nullptr != node->right )
        {
            go_through_nodes( node->right );
            arr.push_back( abs(node->right->val) );
            node->val += node->right->val;
        }
        else if ( nullptr != node->left && nullptr == node->right )
        {
            go_through_nodes( node->left );
            arr.push_back( abs(node->left->val) );
            node->val += node->left->val;
        }
        else
        {
            go_through_nodes( node->right );
            go_through_nodes( node->left );
            const int diff = abs( node->right->val - node->left->val );
            arr.push_back( diff );
            node->val += node->right->val + node->left->val;            
        }
    }
    
};
