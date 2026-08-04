class Solution {
    private:
    bool sol(int i,int j,int idx,vector<vector<char>>& board,string word){
        int n=board.size(),m=board[0].size();
        if(idx==word.size()) return true;
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j]!=word[idx]){
            return false;
        } 
        char tp=board[i][j];
        board[i][j]='#';
        bool found=((sol(i+1,j,idx+1,board,word)) || (sol(i-1,j,idx+1,board,word)) ||
                    (sol(i,j+1,idx+1,board,word)) || (sol(i,j-1,idx+1,board,word)));
    
        board[i][j]=tp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sol(i,j,0,board,word)) return true;
            }
        }
        return false;
    }
};
