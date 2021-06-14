/*
Runtime: 4 ms, faster than 99.98% of C++ online submissions for Single Number.
Memory Usage: 17.1 MB, less than 22.63% of C++ online submissions for Single Number.
*/

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.


*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        ios_base::sync_with_stdio( 0 );
        std::cin.tie( 0 );
        std::cout.tie( 0 );
        
        for ( int i = 1; i < nums.size(); i++ ) 
        
            nums[0] ^= nums[i];
        
        return nums[0];
    }
};
