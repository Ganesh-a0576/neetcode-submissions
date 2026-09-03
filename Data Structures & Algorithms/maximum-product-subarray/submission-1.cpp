class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int curmx=1,curmn=1;
        for(int i:nums){
            int tp=curmx*i;
            curmx=max(max(i*curmx,i*curmn),i);
            curmn=min(min(tp,i*curmn),i);
            ans=max(ans,curmx);
        }
        return ans;
    }
};
