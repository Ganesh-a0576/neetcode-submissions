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
    bool dfs(TreeNode* root,long l,long r){
        if(!root) return true;
        if(!(l<root->val && root->val < r)) return false;
        return ((dfs(root->left,l,root->val)) && (dfs(root->right,root->val,r)));
    }
public:
    bool isValidBST(TreeNode* root) {
       return dfs(root,INT_MIN,INT_MAX);
    }
};
