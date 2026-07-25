class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            int t=nums[i];
            while(!st.empty() && t>st.top().first){
                auto pr=st.top();
                st.pop();
                ans[pr.second]=i-pr.second;
            }
            st.push({t,i});
        }
        return ans;
    }
};
