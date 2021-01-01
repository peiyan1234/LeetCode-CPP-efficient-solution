/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int _index_ = digits.size() - 1;
        while (1)
        {        
            switch (digits[_index_])
            {
                case 9:
                    digits[_index_] = 0;
                    if (_index_ == 0)
                    {
                        digits.insert(digits.begin(), 1);                        
                        return digits;
                    }
                    --_index_;                    
                    break;
                default:
                    ++digits[_index_];
                    return digits;
            }
        }
        return digits;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 9.2 MB, less than 73.93% of C++ online submissions for Plus One.
*/
