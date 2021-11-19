/*
Runtime: 560 ms, faster than 96.61% of C++ online submissions for Swapping Nodes in a Linked List.
Memory Usage: 199.7 MB, less than 5.17% of C++ online submissions for Swapping Nodes in a Linked List.
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> node_arr;
        ListNode* const ans = head;

        while ( head )
        {
            node_arr.push_back(head);
            head = head->next;
        }

        swap( node_arr[ k-1 ]->val, node_arr[ node_arr.size()-k ]->val );

        return ans;
    }
};
