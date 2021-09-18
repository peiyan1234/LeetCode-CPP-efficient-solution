/*
Runtime: 20 ms, faster than 94.56% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.3 MB, less than 80.81% of C++ online submissions for Add Two Numbers.
*/

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    Solution():
    pAns( nullptr ),
    pbuff( nullptr ),
    carry( false ),
    sum( 0 )
    {}
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {           
        while ( l1 || l2 )
        {
            sum = carry;
            if ( l1 ) 
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if ( l2 ) 
            {
                sum += l2->val;
                l2 = l2->next;
            }
                        
            if ( !pAns )
            {
                pAns = new ListNode( sum % 10 );
                pbuff = pAns;
            }
            else
            {
                pbuff->next = new ListNode( sum % 10 );
                pbuff = pbuff->next;
            }
            
            carry = ( sum >= 10 ) ? true : false;
        }
        
        if ( carry )
        {
            pbuff->next = new ListNode( carry );
            pbuff = pbuff->next;
        }
        
        return pAns;
    }
    
private:
    
    ListNode* pAns;   
    ListNode* pbuff;

    bool carry;
    int  sum;
};
