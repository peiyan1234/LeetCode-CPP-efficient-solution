/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
Memory Usage: 7.6 MB, less than 15.54% of C++ online submissions for Reverse Linked List II.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if ( left == right ) return head;

        stack<ListNode*> stack_node;
        ListNode* new_head = nullptr;
        ListNode* tmp_head = nullptr;
        int index = 1;

        bool open_stack = true;

        if ( 1 != left ) new_head = head;
        else index = 0;
        
        while ( head )
        {
            if ( left == index+1 )
            {
                if ( 1==left )
                {
                    stack_node.push( head );
                    tmp_head = head->next;
                    index = 2;
                }
                else
                {
                    stack_node.push( head->next );
                    tmp_head = head->next;
                    index++;
                }
            }
            else if ( left <= index && index <= right )
            {
                stack_node.push( tmp_head );
                tmp_head = tmp_head->next;
                index++;
            }
            else if ( stack_node.empty() )
            {
                if ( right == index-1 )
                {
                    head->next = tmp_head;
                    head = head->next;
                    index++;
                }
                else
                {
                    head = head->next;
                    index++;
                }
                
            }
            else
            {
                if ( 1==left && open_stack )
                {
                    new_head = stack_node.top();
                    open_stack = false;
                    stack_node.pop();
                    head = new_head;
                }
                else
                {
                    head->next = stack_node.top();
                    stack_node.pop();
                    head = head->next;
                }
            }
        }

        return new_head;

}
};
