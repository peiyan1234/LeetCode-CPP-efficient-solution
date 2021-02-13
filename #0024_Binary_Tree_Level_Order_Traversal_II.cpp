/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

class Solution {
public:  
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if (nullptr != root)
        {
            GetNodeValue(root->val);
            root->val = 1;
            Treewalker(root);
            reverse(answer.begin(), answer.end());
        }
        return answer;
    }
    
private:
    size_t level = 1;
    vector<vector<int>> answer;
    void GetNodeValue(int val)
    {
        if (level > answer.size())
            answer.push_back({val});
        else
            answer[level-1].push_back(val);
    }    
    
    void Treewalker(TreeNode* T)
    {
        if (nullptr != T)
        {
            if (nullptr == T->left && nullptr == T->right)
                return;
            
            level = 1+T->val;
            if (nullptr != T->left && nullptr == T->right)
            {
                GetNodeValue(T->left->val);
                T->left->val = 1 + T->val;
                Treewalker(T->left);
            }
            else if (nullptr == T->left && nullptr != T->right)
            {
                GetNodeValue(T->right->val);
                T->right->val = 1 + T->val;
                Treewalker(T->right);
            }
            else
            {
                GetNodeValue(T->left->val);
                GetNodeValue(T->right->val);
                T->left->val = 1 + T->val;
                T->right->val = 1 + T->val;
                Treewalker(T->left);
                Treewalker(T->right);
            }
        }
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 12.7 MB, less than 66.43% of C++ online submissions for Binary Tree Level Order Traversal II.
*/
