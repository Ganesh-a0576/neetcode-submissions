class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0,b=0;
        for(int i:nums){
            int cur=max(a,b+i);
            b=a;
            a=cur;
        }
        return a;
    }
};
