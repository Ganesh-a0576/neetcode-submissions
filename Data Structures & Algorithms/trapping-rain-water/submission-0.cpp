class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size(),l=0,r=n-1,lm=0,rm=0,ans=0;
        while(l<r){
            lm=max(lm,a[l]);
            rm=max(rm,a[r]);
            ans+=(lm<rm)?lm-a[l++]:rm-a[r--];
        }
        return ans;
    }
};
