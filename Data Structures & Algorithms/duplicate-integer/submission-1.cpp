class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int s=nums[i];
            for(int j=i+1;j<nums.size();j++){
            if(s==nums[j]) return true;
        }}
        return false;
    }
};
