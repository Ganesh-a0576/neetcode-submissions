class Solution {
public:
    int singleNumber(vector<int>& ar) {
        int a=0,b=0;
        for(int i=0;i<ar.size();i++){
            a=a^(ar[i]);
            b=b^(ar[i]);
        }
        return a;
    }
};
