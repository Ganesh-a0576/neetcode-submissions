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
    private:
    int dfs(TreeNode* root,int &ans){
        if(!root) return 0;
        int lft=max(dfs(root->left,ans),0);
        int rt=max(dfs(root->right,ans),0);

        ans=max(ans,root->val+lft+rt);
        return root->val+max(lft,rt);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        dfs(root,ans);
        return ans;
    }
};
