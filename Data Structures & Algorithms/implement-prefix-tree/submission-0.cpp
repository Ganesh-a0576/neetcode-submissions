class PrefixTree {
    struct TreeNode{
        bool isend;
        unordered_map<char,TreeNode*> child;
        TreeNode(){
            isend=false;
        }
    };
    TreeNode *root;
public:
    PrefixTree() {
        root=new TreeNode();
    }
    
    void insert(string word) {
        TreeNode *cur=root;
        for(char c:word){
            if(!cur->child.count(c)){
                cur->child[c]=new TreeNode();
            }
            cur=cur->child[c];
        }
        cur->isend=true;
    }
    
    bool search(string word) {
        TreeNode *cur=root;
        for(char c:word){
            if(!cur->child.count(c)){
                return false;
            }
            cur=cur->child[c];
        }
        return cur->isend;
    }
    
    bool startsWith(string prefix) {
        TreeNode *cur=root;
        for(char c:prefix){
            if(!cur->child.count(c)){
                return false;
            }
            cur=cur->child[c];
        }
        return true;
    }
};
