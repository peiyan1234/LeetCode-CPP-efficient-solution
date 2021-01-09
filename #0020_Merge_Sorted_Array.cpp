/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

 

Constraints:

    0 <= n, m <= 200
    1 <= n + m <= 200
    nums1.length == m + n
    nums2.length == n
    -109 <= nums1[i], nums2[i] <= 109


*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        
        if (n)
        {            
            vector<int> buffer;
            int index1 = 0;            
            while (index1 < m)
            {
                buffer.push_back(nums1[index1]);
                ++index1;
            }
            
            index1 = 0;
            int index2 = 0;            
            while (index2 < n || index1 < m)
            {
                if (index2 < n && index1 < m)
                {
                    if (nums2[index2] > buffer[index1])
                    {
                        nums1[index1 + index2] = buffer[index1];
                        ++index1;
                    }
                    else
                    {
                        nums1[index1 + index2] = nums2[index2];
                        ++index2;
                    }
                }
                else if (index2 < n)
                {
                    nums1[index1 + index2] = nums2[index2];
                    ++index2;
                }
                else
                {
                    nums1[index1 + index2] = buffer[index1];
                    ++index1;
                }
            }            
        }
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
Memory Usage: 9.4 MB, less than 83.49% of C++ online submissions for Merge Sorted Array.
*/
