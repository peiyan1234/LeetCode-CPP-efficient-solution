/*
Runtime: 28 ms, faster than 86.59% of C++ online submissions for Linked List in Binary Tree.
Memory Usage: 32 MB, less than 98.00% of C++ online submissions for Linked List in Binary Tree.
*/

class Solution {
public:
    bool isinside(ListNode* listnode,TreeNode* treenode )
    {
        if ( nullptr == treenode ) return false;
        
        if ( listnode->val == treenode->val )
        {
            if ( nullptr == listnode->next ) return true;
            else
            {
                if ( isinside( listnode->next, treenode->left )
                   || isinside( listnode->next, treenode->right ) ) return true;
                return false;
            }
        }
        else
        {
            return false;
        }      
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if ( nullptr == root ) return false;
        if ( isinside( head, root ) ) return true;
        else
        {
            if ( isSubPath( head, root->left ) || isSubPath( head, root->right ) ) return true;
            else return false;
        }
        
    }
};
