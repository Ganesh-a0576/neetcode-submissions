class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> fq(256,0);
        int l=0,n=s.length(),ans=0;
        for(int r=0;r<n;r++){
            fq[s[r]]++;
            while(fq[s[r]] >1){
                fq[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
