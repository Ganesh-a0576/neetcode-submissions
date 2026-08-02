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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto comp=[](ListNode *a,ListNode *b){
            return a->val > b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> pq(comp);

        for(ListNode *it:lists){
            pq.push(it);
        }

        ListNode dm(0);
        ListNode *cur=&dm;

        while(!pq.empty()){
            ListNode *nd=pq.top();
            pq.pop();

            cur->next=nd;
            cur=cur->next;

            if(nd->next) pq.push(nd->next);
        }
        return dm.next;
    }
};
