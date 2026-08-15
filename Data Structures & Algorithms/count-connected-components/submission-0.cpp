class Solution {
    private:
    void dfs(int nd,unordered_set<int>& vis,vector<vector<int>>& adj){
        vis.insert(nd);
        for(int i:adj[nd]){
            if(!vis.count(i)){
                dfs(i,vis,adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_set<int> vis;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis.count(i)){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
