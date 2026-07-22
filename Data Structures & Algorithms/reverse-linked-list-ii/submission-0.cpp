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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dm=new ListNode(0);
        dm->next=head;
        //# phase 1 reach left node 
        ListNode *lprv=dm,*cur=head;
        for(int i=0;i<left-1;i++){
            lprv=cur;
            cur=cur->next;
        }
        //# phase 2 reverse left to right 
        ListNode* prv=nullptr;
        for(int i=0;i<right-left+1;i++){
            ListNode *tp=cur->next;
            cur->next=prv;
            prv=cur;
            cur=tp;
        }
        //# phase 3 connection for lprv and prev and cur 
        lprv->next->next=cur;
        lprv->next=prv;
        return dm->next;
    }
};