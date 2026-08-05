class WordDictionary {
    private:
    struct TrieNode{
        bool isend;
        unordered_map<char,TrieNode*> child;
        TrieNode(){
            isend=false;
        }
    };
    TrieNode *root;
    bool dfs(string word,int i,TrieNode *root){
        if(i==word.size()) return root->isend;
        char c=word[i];
        if(c=='.'){
            for(auto &p:root->child){
                if(dfs(word,i+1,p.second)) return true;
            }
            return false;
        }
        if(!root->child.count(c)) return false;

        return dfs(word,i+1,root->child[c]);
    }
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur=root;
        for(char c:word){
            while(!cur->child.count(c)){
                cur->child[c]=new TrieNode();
            }
            cur=cur->child[c];
        }
        cur->isend=true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
