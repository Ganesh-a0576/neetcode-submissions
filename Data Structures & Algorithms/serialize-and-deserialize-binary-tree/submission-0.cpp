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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        
        auto dfs=[&](auto&& dfs,TreeNode* root,string &s)->void{
            if(!root){
                s+="N,";
                return;
            }
            s+=to_string(root->val)+",";
            dfs(dfs,root->left,s);
            dfs(dfs,root->right,s);
        };
        dfs(dfs,root,s);
        return s;  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        auto dfs=[&](auto&& dfs,stringstream &ss)->TreeNode*{
            string x;
            getline(ss,x,',');

            if(x=="N") return nullptr;

            TreeNode *root=new TreeNode(stoi(x));
            root->left=dfs(dfs,ss);
            root->right=dfs(dfs,ss);
            return root;

        };
        return dfs(dfs,ss);
    }
};
