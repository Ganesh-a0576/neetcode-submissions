class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sm=0,mx=nums[0];
        for(int i:nums){
            sm+=i;
            if(sm>mx) mx=max(sm,mx);
            if(sm<0) sm=0;
        }
        return mx;
    }
};
