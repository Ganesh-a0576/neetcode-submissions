class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> t;
        for(int i:nums){
            auto it=lower_bound(t.begin(),t.end(),i);
            if(it==t.end()) t.push_back(i);
            else *it=i;
        }
        return t.size();
    }
};
