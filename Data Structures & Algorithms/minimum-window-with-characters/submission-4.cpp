class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        int l=0,cnt=t.length(),mxl=INT_MAX,st=0;
        vector<int> nd(128,0);
        for(char c:t) nd[c]++;
        for(int r=0;r<s.size();r++){
            if(nd[s[r]] >0) cnt--;
            nd[s[r]]--;
            while(cnt==0){
                //mxl=min(mxl,nd[s[l]]);
                if(r-l+1 < mxl){
                    mxl=r-l+1;
                    st=l;
                }
                nd[s[l]]++;
                if(nd[s[l]] >0) cnt++;
                l++;
            }
        }
        return mxl==INT_MAX?"":s.substr(st,mxl);
    }
};
