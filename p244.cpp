class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        
        stack<ListNode*> stck;
        ListNode* curr = head;
        
        while (curr != NULL)
        {
            stck.push(curr);
            curr = curr->next;
        }
        
        ListNode* new_head = stck.top();
        while(1)
        {
            ListNode* node = stck.top();
            stck.pop();
            if (stck.empty())
            {
                node->next = NULL;
                break;
            }
            else
            {
                node->next = stck.top();
            }
            
        }
        
        return new_head;
    }
};