/*
Runtime: 264 ms, faster than 96.35% of C++ online submissions for Merge In Between Linked Lists.
Memory Usage: 94.5 MB, less than 14.18% of C++ online submissions for Merge In Between Linked Lists.
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* ans = list1;
        int index = 0;
        
        
        while ( index < a-1 )
        {
            list1 = list1->next;
            index++;
        }
        
        ListNode* buf_node = list1->next;
        index++;
        
        list1->next = list2;
        
        while ( index <= b )
        {
            buf_node = buf_node->next;
            index++;
        }
        
        while ( list1->next )
        {
            list1 = list1->next;
        }
        
        list1->next = buf_node;
        
        return ans;
    }
};
