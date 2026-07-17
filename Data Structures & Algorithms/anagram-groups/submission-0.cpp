class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string,vector<string>> res;
        for(auto& st:s){
            vector<int> c(26,0);
            for(char ch:st){
                c[ch-'a']++;
            }
            string k;
            for(int i:c){
                k+="#"+to_string(i);
            }
            res[k].push_back(st);
        }
        vector<vector<string>> ans;
        for(auto& g:res){
            ans.push_back(g.second);
        }
        return ans;
    }
};
