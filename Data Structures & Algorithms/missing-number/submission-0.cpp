class Solution {
public:
    int missingNumber(vector<int>& a) {
        int s=a.size(),v=0;
        int g=s*(s+1)/2;
        for(int i:a){
            v+=i;
        }
        return g-v;
    }
};
