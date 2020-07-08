/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr or l2 == nullptr)
        {
            if (l1 != nullptr)
                return l1;
            return l2;
        }
        
        ListNode *buffer_list = nullptr;
        buffer_list = new ListNode();
        ListNode *ans = buffer_list;
        
        while (l1 != nullptr and l2 != nullptr)
        {
            if (l1 -> val > l2 -> val)
            {
                buffer_list -> val = l2 -> val;
                buffer_list -> next = new ListNode();
                buffer_list = buffer_list -> next;
                l2 = l2 -> next;
                buffer_list -> val = l1 -> val;
                buffer_list -> next = nullptr;
                if (l2 == nullptr)
                    buffer_list -> next = l1 -> next;
            }
            else
            {
                buffer_list -> val = l1 -> val;
                buffer_list -> next = new ListNode();
                buffer_list = buffer_list -> next;
                l1 = l1 -> next;
                buffer_list -> val = l2 -> val;
                buffer_list -> next = nullptr;
                if (l1 == nullptr)
                    buffer_list -> next = l2 -> next;
            }
        } 

        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.6 MB, less than 35.23% of C++ online submissions for Merge Two Sorted Lists.
*/
