/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        unsigned int vec_size = nums.size();
        
        if (target <= nums[0]) return 0;
        
        unsigned short _index_ = 0;
        while (_index_ < vec_size - 1)
        {
            if (target > nums[_index_] && target <= nums[_index_ + 1]) return _index_ + 1;
            ++_index_;
        }
        
        return vec_size;
    }
};

/*
Runtime: 4 ms, faster than 99.13% of C++ online submissions for Search Insert Position.
Memory Usage: 10 MB, less than 99.99% of C++ online submissions for Search Insert Position.
*/
