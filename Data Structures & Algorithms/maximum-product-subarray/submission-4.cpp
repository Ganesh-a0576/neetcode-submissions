class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),pre=0,sf=0,ans=nums[0];
        for(int i=0;i<n;i++){
            pre=nums[i]*(pre==0?1:pre);
            sf=nums[n-i-1]*(sf==0?1:sf);
            ans=max(ans,max(pre,sf));
        }
        return ans;
    }
};
