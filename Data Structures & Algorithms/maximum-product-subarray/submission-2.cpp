class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),pr=0,sf=0,ans=nums[0];
        for(int i=0;i<n;i++){
            pr=nums[i]*(pr==0?1:pr);
            sf=nums[n-i-1]*(sf==0?1:sf);
            ans=max(ans,max(pr,sf));
        }
        return ans;
    }
};
