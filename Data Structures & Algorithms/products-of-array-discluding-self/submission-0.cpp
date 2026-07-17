class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n=a.size();
        vector<int> ans(n,1);
        int pr=1;
        for(int i=0;i<n;i++){
            ans[i]=pr;
            pr*=a[i];
        }
        int po=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=po;
            po*=a[i];
        }
        return ans;
    }
};
