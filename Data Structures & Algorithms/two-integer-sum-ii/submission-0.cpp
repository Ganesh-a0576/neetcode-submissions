class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            int sm=nums[i]+nums[j];
            if(sm==target) return {i+1,j+1};
            else if(sm<target) i++;
            else j--;
        }
        return {-1,-1};
    }
};
