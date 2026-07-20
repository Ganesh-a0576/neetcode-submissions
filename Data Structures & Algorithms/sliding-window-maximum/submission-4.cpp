class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(),l=0,r=0;
        deque<int> d;
        vector<int> ans;
        while(r<n){
            while(!d.empty() && nums[d.back()]<nums[r]) d.pop_back();
            d.push_back(r);
            if(l>d.front()){
                d.pop_front();
            }
            if(r+1 >=k){
                ans.push_back(nums[d.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
