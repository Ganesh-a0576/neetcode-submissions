class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {

        int n=a.size(),m=a[0].size(),tp=0,bt=n-1,l=0,r=m-1;
        vector<int> ans;
        if (a.empty() || a[0].empty()) return {};
        while(tp<=bt && l<=r){
            for(int i=l;i<=r;i++){
                ans.push_back(a[tp][i]);
            }
            tp+=1;

            for(int i=tp;i<=bt;i++){
                ans.push_back(a[i][r]);
            }
            r-=1;
            if(tp<=bt){
                for(int i=r;i>=l;i--){
                    ans.push_back(a[bt][i]);
                }
                bt-=1;
            }
            if(l<=r){
                for(int i=bt;i>=tp;i--){
                    ans.push_back(a[i][l]);
                }
                l+=1;
            }
        }
        return ans;
    }
};
