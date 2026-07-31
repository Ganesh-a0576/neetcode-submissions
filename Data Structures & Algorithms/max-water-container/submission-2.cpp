class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size(),l=0,r=n-1,ans=0;
        while(l<r){
            int wt=r-l,ht=min(heights[l],heights[r]);
            ans=max(ans,wt*ht);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
