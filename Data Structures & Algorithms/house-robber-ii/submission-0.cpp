class Solution {
    private:
        int rob1(vector<int>& nums,int l,int r){
            int a=0,b=0;
            for(int i=l;i<=r;i++){
                int cur=max(a,b+nums[i]);
                b=a;
                a=cur;
            }
            return a;
        }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return (max(rob1(nums,0,n-2),rob1(nums,1,n-1)));
    }
};
// class Solution {
// private:
//     int rob1(vector<int>& nums, int l, int r) {
//         int a = 0, b = 0;

//         for (int i = l; i <= r; i++) {
//             int cur = max(a, b + nums[i]);
//             b = a;
//             a = cur;
//         }

//         return a;
//     }

// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1)
//             return nums[0];

//         return max(
//             rob1(nums, 0, n - 2),
//             rob1(nums, 1, n - 1)
//         );
//     }
// };
