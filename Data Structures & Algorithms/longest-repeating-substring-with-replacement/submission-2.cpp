class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length(),l=0,mxl=0,ans=0;
        vector<int> fq(26,0);
        for(int r=0;r<n;r++){
            fq[s[r]-'A']++;
            mxl=max(mxl,fq[s[r]-'A']);
            while((r-l+1)-mxl > k){
                fq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
