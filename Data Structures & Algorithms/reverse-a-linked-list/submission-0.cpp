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
    ListNode* reverseList(ListNode* head) {
        ListNode *pv=nullptr,*cur=head;
        while(cur!=NULL){
            ListNode *nxt=cur->next;
            cur->next=pv;
           // pv->next=nxt;
            pv=cur;
            cur=nxt;
        }
        return pv;
    }
};
