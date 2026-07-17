class Solution {
public:
    int search(vector<int>& a, int t) {
        int n=a.size();
        int h=n-1,l=0;
        while(l<=h){
            int m=l+((h-l)/2);
            if(a[m]>t){
                h=m-1;
            }
            else if(a[m]<t){
                l=m+1;
            }
            else return m;
        }
        return -1;
    }
};
