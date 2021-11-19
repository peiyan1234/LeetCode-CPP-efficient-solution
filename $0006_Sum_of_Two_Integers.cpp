/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
Memory Usage: 5.9 MB, less than 72.85% of C++ online submissions for Sum of Two Integers.
*/

class Solution {
public:
    int getSum(int a, int b) {
        
        if ( 0 == a ) return b;
        if ( 0 == b ) return a;
        
        while ( b != 0 )
        {
            unsigned carry = a & b;
            a = a ^ b;
            b = carry << 1;            
        }
        return a;
    }
};
