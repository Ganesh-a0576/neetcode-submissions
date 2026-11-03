class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        int n=a.size(),M=a[0].size();
        int l=0,h=n*M-1;
        while(l<=h){
            int m=l+(h-l)/2;
            int m1=m/M;
            int m2=m%M;
            if(a[m1][m2]==k) return true;
            else if(a[m1][m2]<k) l=m+1;
            else h=m-1;
        }
        return false;
    }
};
