class Solution {
    private:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> vis;
    bool dfs(int cur){
        if(vis.count(cur)) return false;
        if(mp[cur].empty()) return true;
        vis.insert(cur);
        for(int i:mp[cur]){
            if(!dfs(i)) return false;
        }
        vis.erase(cur);
        mp[cur].clear();
        return true;
    }
public:
    bool canFinish(int numc, vector<vector<int>>& nums) {
        for(int i=0;i<numc;i++){
            mp[i]={};
        }

        for(const auto& i:nums){
            mp[i[0]].push_back(i[1]);
        }

        for(int i=0;i<numc;i++){
            if(!dfs(i)) return false;
        }
        return true;
    }
};
