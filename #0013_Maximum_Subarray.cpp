/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        size_t _index_ = 1;
        int ANS, min;
        ANS = nums[0];
        if (nums[0] < 0)
            min = nums[0];
        else
            min = 0;
        while (_index_ < nums.size()) 
        {
            nums[_index_] = nums[_index_] + nums[_index_ - 1];
            if (nums[_index_] - min > ANS)
                ANS = nums[_index_] - min;  
            if (nums[_index_] < min)
                min = nums[_index_];
            ++_index_;                    
        }
        return ANS;
    }
};

/*
Runtime: 8 ms, faster than 96.25% of C++ online submissions for Maximum Subarray.
Memory Usage: 13.4 MB, less than 92.49% of C++ online submissions for Maximum Subarray.
*/
