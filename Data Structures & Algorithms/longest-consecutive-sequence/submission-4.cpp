class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),count=1,mx=1;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1) count++;
            else count=1;
            mx=max(mx,count);
        }
        return mx;
    }
};
