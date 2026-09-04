class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        int k=sum/2;
        if(sum%2!=0) return false;
        vector<bool> dp(k+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=k;j>=nums[i];j--){
                dp[j]=dp[j] || dp[j-nums[i]];
            }
        }
        return dp[k];
    }
};
