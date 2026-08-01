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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if(!head || (!head->next && n>=1)) return nullptr;
        ListNode dm(0);
        dm.next=head;
        ListNode *f=&dm,*s=&dm;
        for(int i=0;i<=n;i++){
            f=f->next;
        }
        while(f){
            f=f->next;
            s=s->next;
        }
        ListNode *tp=s->next;
        s->next=s->next->next;
        delete(tp);
        return dm.next;
        
    }
};
