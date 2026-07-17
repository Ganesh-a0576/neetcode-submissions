class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;  
        for (int num : nums) {  
            f[num]++;  
        } 
        vector<pair<int, int>> fv(f.begin(), f.end());
        sort(fv.begin(), fv.end(), [](const pair<int, int>& a, const pair<int, int>& b) {  
            return a.second > b.second; 
        });  
        vector<int> ans;  
        for (int i = 0; i < k; i++) {  
            ans.push_back(fv[i].first);
        }  
        return ans;
    }
};
