class Solution {
public:
    bool hasDuplicate(vector<int>& a) {
        unordered_map<int,int> hs;
        for(int i:a){
            if(hs[i]>0) return true;
            hs[i]++;
        }
       return false;
    }
};
