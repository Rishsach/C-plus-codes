
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        
        ListNode *p = head;
        ListNode *q = p;
        while (p) {
            q = p->next;
            if (q && (q->val == p->val)) {
                p->next = q->next;
                delete q;
            }
            else
                p = p->next;
        }
        return head;
    }
};
    