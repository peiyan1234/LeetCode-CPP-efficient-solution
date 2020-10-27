/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 

Constraints:

1 <= n <= 30
*/

class Solution {
public:  
    string countAndSay(int n) {
        switch (n)
        {
            case 1:
                return "1";
            case 2:
                return "11";
        }

        string init_case = "11";
        int _index_ = 2;
        while (_index_ < n)
        {
            init_case = next_case(init_case);
            ++_index_;
        }
        return init_case;

    }
    
    string next_case(string init_case) {
        int _reader_ = 0;
        int counter = 0;
        char _cbox_ = init_case[0];
        string ans_case = "";
        while (_reader_ < init_case.size())
        {
            if (_cbox_ != init_case[_reader_]) 
            {
                ans_case += to_string(counter) + _cbox_;
                _cbox_ = init_case[_reader_];
                counter = 1;
            }
            else counter += 1;
            if (_reader_ == init_case.size() - 1 and counter > 0)
                ans_case += to_string(counter) + _cbox_;
            ++_reader_;
        }
        return ans_case;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count and Say.
Memory Usage: 7.3 MB, less than 14.93% of C++ online submissions for Count and Say.
*/
