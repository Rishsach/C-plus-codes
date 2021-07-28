
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* pre=head;
        for(n;n>=1;n--) p=p->next;
        if(p==NULL)return head->next;
        while(p->next!=NULL){
            p=p->next;
            pre=pre->next;
        }
        pre->next=pre->next->next;
        return head;
    }
};
