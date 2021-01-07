/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

class Solution {
public:
    int climbStairs(int n) {
        int ANS = 1;
        int _k_ = 1;
        int _index_ = 1;
        while (_index_ < n)
        {
            ANS = _k_ + ANS;
            _k_ = ANS - _k_;
            ++_index_;
        }
        
        return ANS;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
Memory Usage: 6.2 MB, less than 91.52% of C++ online submissions for Climbing Stairs.
*/
