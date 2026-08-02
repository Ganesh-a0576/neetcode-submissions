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
        queue<TreeNode*> qp,qq;
        qp.push(p);qq.push(q);
        while(!qp.empty() && !qq.empty()){
            for(int i=qp.size();i>0;i--){
                TreeNode *a=qp.front();qp.pop();
                TreeNode *b=qq.front();qq.pop();

                if(!a && !b) continue;
                if(!a || !b || a->val != b->val) return false;

                qp.push(a->left);
                qp.push(a->right);

                qq.push(b->left);
                qq.push(b->right);
            }
        }
        return true;
    }
};
