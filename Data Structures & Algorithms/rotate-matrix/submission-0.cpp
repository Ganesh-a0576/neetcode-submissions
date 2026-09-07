class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        ranges::reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a[0].size();j++){
                swap(a[i][j],a[j][i]);
            }
        }
    }
};
