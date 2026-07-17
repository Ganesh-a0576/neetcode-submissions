class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n=a.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int g=a[i];
            for(int j=i+1;j<n;j++){
                if(g+a[j]==t){
                    ans={i,j};
                }
            }
        }
        return ans;
    }
};
