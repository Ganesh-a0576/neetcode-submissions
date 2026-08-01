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
        auto comp=[](const ListNode *a,ListNode *b){
            return b->val < a->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> pq(comp);
        for(ListNode* lt:lists){
            if(lt) pq.push(lt);
        }
        ListNode dm(0);
        ListNode *cur=&dm;
        while(!pq.empty()){
            ListNode *nd=pq.top();
            pq.pop();

            cur->next=nd;
            cur=cur->next;

            if(nd->next){
                pq.push(nd->next);
            }
        }
        return dm.next;

    }
};
