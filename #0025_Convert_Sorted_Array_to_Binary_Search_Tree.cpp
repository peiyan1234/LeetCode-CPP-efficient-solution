/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        switch (nums.size())
        {
            case 1:
                BSTree -> val = nums[0];
                break;
            case 2:
                BSTree -> val = nums[1];
                BSTree -> left = new TreeNode(nums[0]);
                break;
            case 3:
                BSTree -> val = nums[1];
                BSTree -> left = new TreeNode(nums[0]);
                BSTree -> right = new TreeNode(nums[2]);
                break;
            default:
                num_vect = nums;
                BSTree -> val = nums[nums.size() / 2];
                BSTree -> left = new TreeNode();
                BSTree -> right = new TreeNode();
                TreeGrowUp(BSTree -> left, 0, nums.size() / 2);
                TreeGrowUp(BSTree -> right, nums.size() / 2 + 1, nums.size());
        }
        return BSTree;
    }
private:
    vector<int> num_vect;
    TreeNode* BSTree = new TreeNode();
    void TreeGrowUp(TreeNode* node, size_t start_point, size_t end_point)
    {
        node -> val = num_vect[(start_point + end_point) / 2];
        switch (end_point - start_point - 1)
        {
            case 0:
                break;
            case 1:
                node -> left = new TreeNode(num_vect[(start_point + end_point) / 2 - 1]);
                break;
            case 2:
                node -> left = new TreeNode(num_vect[(start_point + end_point) / 2 - 1]);
                node -> right = new TreeNode(num_vect[(start_point + end_point) / 2 + 1]);
                break;
            default:
                node -> left = new TreeNode();
                node -> right = new TreeNode();
                TreeGrowUp(node -> left, start_point, (start_point + end_point) / 2);
                TreeGrowUp(node -> right, (start_point + end_point) / 2 + 1, end_point);
        }
    }
};


/*
Runtime: 8 ms, faster than 99.91% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 20.5 MB, less than 100.00% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
*/
