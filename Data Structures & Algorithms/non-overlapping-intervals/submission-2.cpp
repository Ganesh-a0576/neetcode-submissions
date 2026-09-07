class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n=a.size(),cnt=0;
        sort(a.begin(),a.end(),[](vector<int> i,vector<int> j){return i[1]<j[1];});
        int lstv=a[0][1];
        for(int i=1;i<n;i++){
            if(lstv>a[i][0]){
                cnt++;
            }
            else {
                lstv=a[i][1];
            }
        }
        return cnt;
    }
};
