class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mps,mpt;
        for(char i:s) mps[i]++;
        for(char i:t) mpt[i]++;
        if(mps.size()==mpt.size()){
            for(auto const& [key, val] : mps){
                if(mps[key] != mpt[key]) return false;
            }
            return true;
        }
        else return false;
    }
};
