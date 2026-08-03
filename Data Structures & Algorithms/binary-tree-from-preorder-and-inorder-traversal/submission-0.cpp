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
    unordered_map<int,int> mp;
    TreeNode *dfs(vector<int> &pre,int pL,int pR,vector<int> &ino,int inL,int inR){
        if(pL > pR || inL >inR) return nullptr;
        TreeNode *root=new TreeNode(pre[pL]);
        int idx=mp[root->val];
        int idxsz=idx-inL;

        root->left=dfs(pre,pL+1,pL+idxsz,ino,inL,idx-1);
        root->right=dfs(pre,pL+idxsz+1,pR,ino,idx+1,inR);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return dfs(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
