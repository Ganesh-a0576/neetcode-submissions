class Solution {
    private:
    void sol(int idx,vector<int> &nums,int k,vector<int>& ds,vector<vector<int>>& ans){
        if(idx==nums.size()){
            if(k==0) ans.push_back(ds);
            return;
        }

        if(nums[idx]<=k){
            ds.push_back(nums[idx]);
            sol(idx,nums,k-nums[idx],ds,ans);
            ds.pop_back();
        }
        sol(idx+1,nums,k,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sol(0,nums,target,ds,ans);
        return ans;
    }
};
