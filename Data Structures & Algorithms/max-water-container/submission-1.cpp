class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size(),i=0,j=n-1,m=0;
        while(i<=j){
            int ar=(j-i)*min(a[i],a[j]);
            m=max(m,ar);
            if(a[i]<a[j]) i++;
            else j--;
        }
        return m;
    }
};
