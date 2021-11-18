/*
Runtime: 4 ms, faster than 95.71% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.5 MB, less than 10.44% of C++ online submissions for Reverse Linked List.
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
        ListNode* reverseList(ListNode* head)
        {
            if ( head )
            {
                ListNode* new_head = nullptr;

                stack<ListNode*> stack_node;
                while ( head )
                {
                    stack_node.push( head );
                    head = head->next;
                }

                bool open_stack = true;
                ListNode* buf_node = nullptr;
                while ( !stack_node.empty() )
                {
                    if ( open_stack )
                    {
                        open_stack = false;
                        new_head = stack_node.top();
                        buf_node = new_head;
                        stack_node.pop();
                    }
                    else
                    {
                        buf_node->next = stack_node.top();
                        buf_node = buf_node->next;
                        stack_node.pop();
                    }
                }
                buf_node->next = nullptr;

                return new_head;
            }

            return head;
        }
};
