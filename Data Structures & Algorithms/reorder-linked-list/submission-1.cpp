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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *s=head,*f=head->next;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode *second=s->next;
        ListNode *pv=s->next=nullptr;
        while(second!=NULL){
            ListNode *tp=second->next;
            second->next=pv;
            pv=second;
            second=tp;
        }
        ListNode *first=head;
        second = pv;

        while(second){
            ListNode *t2=second->next,*t1=first->next;
            
            first->next=second;
            second->next=t1;

            first=t1;
            second=t2;
            
        }
    }
};
