class Solution {
    private:
    bool dfs(int nd,int pt,unordered_set<int>& vis,vector<vector<int>>& adj){
        if(vis.count(nd)) return false;
        vis.insert(nd);
        for(int i:adj[nd]){
            if(i==pt) continue;
            if(!dfs(i,nd,vis,adj)) return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        unordered_set<int> vis;
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        if(!dfs(0,-1,vis,adj)) return false;
        return vis.size()==n;
    }
};
