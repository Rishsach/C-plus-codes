class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res=new ListNode(0);//添加头结点
        res->next=head;
        ListNode* tmp=res;
        while(tmp->next){
            if(tmp->next->val==val) tmp->next=tmp->next->next;
            else tmp=tmp->next;
        }
        return res->next;
    }
};