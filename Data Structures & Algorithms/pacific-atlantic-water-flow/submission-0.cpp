class Solution {
    private:
        void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<unsigned char>>& vis,unsigned char oc){
            int n=heights.size(),m=heights[0].size();
            int dr[4]={1,-1,0,0};
            int dc[4]={0,0,1,-1};
            vis[i][j] |= oc;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(vis[nr][nc] & oc) continue;
                if(heights[nr][nc] < heights[i][j]) continue;
                dfs(nr,nc,heights,vis,oc);
            }
        }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<unsigned char>> vis(n,vector<unsigned char> (m,0));
        //pacific ocean
        for(int i=0;i<n;i++) dfs(i,0,heights,vis,1);

        for(int j=0;j<m;j++) dfs(0,j,heights,vis,1);

        // Atlanic ocean
        for(int i=0;i<n;i++) dfs(i,m-1,heights,vis,2);

        for(int j=0;j<m;j++) dfs(n-1,j,heights,vis,2); 

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 3) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
