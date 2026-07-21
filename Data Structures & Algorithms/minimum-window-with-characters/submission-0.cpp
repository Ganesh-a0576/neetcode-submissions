class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int> cnT,win;
        for(char c:t) cnT[c]++;
        int hv=0,nd=cnT.size(),l=0;
        pair<int,int> res{-1,-1};
        int resL=INT_MAX;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            win[c]++;
            if(cnT.count(c) && win[c]==cnT[c]) hv++;
            while(hv==nd){
                if((r-l+1) < resL){
                    resL=r-l+1;
                    res={l,r};
                }
                win[s[l]]--;
                if(cnT.count(s[l]) && win[s[l]] < cnT[s[l]]) hv--;
                l++;
            }
        }
        return resL==INT_MAX ? "" : s.substr(res.first,resL); 
    }
};
