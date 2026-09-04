class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        int k=sum/2;
        if(sum%2!=0) return false;
        bitset<10001> dp;
        dp[0]=1;
        for(int i:nums){
            dp |= dp<<i;
        }
        return dp[k];
    }
};
