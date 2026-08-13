class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>>& h,vector<vector<unsigned char>>& vis,unsigned char oc){
        int n=h.size(),m=h[0].size();

        vis[i][j] |=oc;
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(h[nr][nc] < h[i][j]) continue;
            if(vis[nr][nc] & oc) continue;

            dfs(nr,nc,h,vis,oc);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        vector<vector<unsigned char>> vis(n,vector<unsigned char>(m,0));

        // pec 
        for(int i=0;i<n;i++) dfs(i,0,nums,vis,1);
        for(int j=0;j<m;j++) dfs(0,j,nums,vis,1);

        // alt 
        for(int i=0;i<n;i++) dfs(i,m-1,nums,vis,2);
        for(int j=0;j<m;j++) dfs(n-1,j,nums,vis,2);

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==3) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
