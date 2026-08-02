/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // queue<TreeNode*> qp,qq;
        // qp.push(p);qq.push(q);
        // while(!qp.empty() && !qq.empty()){
        //     int sz=qp.size();
        //     for(int i=sz;i>0;i--){
        //         TreeNode *a=qp.front();
        //         qp.pop();
        //         TreeNode *b=qq.front();
        //         qq.pop();

        //         if(!a && !b) continue;
        //         if(!a || !b || a->val != b->val) return false;

        //         if(a->left) qp.push(a->left);
        //         if(q->right) qp.push(a->right);

        //         if(b->left) qq.push(b->left);
        //         if(b->right) qq.push(b->right);
        //     }
        // }
        // return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            for (int i = q1.size(); i > 0; i--) {
                TreeNode* nodeP = q1.front(); q1.pop();
                TreeNode* nodeQ = q2.front(); q2.pop();

                if (!nodeP && !nodeQ) continue;
                if (!nodeP || !nodeQ || nodeP->val != nodeQ->val)
                    return false;

                q1.push(nodeP->left);
                q1.push(nodeP->right);
                q2.push(nodeQ->left);
                q2.push(nodeQ->right);
            }
        }

        return true;
    }
};
