class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0,b=0;
        for(int i:nums){
            int c=max(a,b+i);
            b=a;
            a=c;
        }
        return a;
    }
};
