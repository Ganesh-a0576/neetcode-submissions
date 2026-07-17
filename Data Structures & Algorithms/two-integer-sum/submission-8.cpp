class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int sm=target-nums[i];
            if(mp.count(sm)) return {mp[sm],i};
            mp[nums[i]]=i;
        }
        return {};
    }
};
