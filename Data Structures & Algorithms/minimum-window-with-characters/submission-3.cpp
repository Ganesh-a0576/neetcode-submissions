class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() >s.length()) return "";
        vector<int> nd(128,0);
        int l=0,cnt=t.size(),mn=INT_MAX,st=0;
        for(char c:t) nd[c]++;
        for(int r=0;r<s.length();r++){
            if(nd[s[r]] >0) cnt--;
            nd[s[r]]--;

            while(cnt==0){
                if(r-l+1 < mn) {
                    mn=r-l+1;
                    st=l;
                }
                nd[s[l]]++;
                if(nd[s[l]] >0) cnt++;
                l++;
            }
        }
        return mn==INT_MAX?"":s.substr(st,mn);
    }
};
