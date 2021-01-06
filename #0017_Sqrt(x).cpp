/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
*/

class Solution {
public:
    int mySqrt(int x) {
        long ANS = x / 2;
        int up_bound = x;
        while (1)
        {
            if (ANS * ANS <= x && ANS * ANS + 2 * ANS > x - 1)
                break;
            else
            {
                if (ANS * ANS > x)
                {
                    up_bound = ANS;
                    ANS = ANS / 2;
                }
                if (ANS * ANS < x)
                    ANS = (ANS + up_bound) / 2;
            }
            if (ANS == 0)
                ANS = 1;
        }       
        return ANS;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
Memory Usage: 6.2 MB, less than 89.91% of C++ online submissions for Sqrt(x).
*/
