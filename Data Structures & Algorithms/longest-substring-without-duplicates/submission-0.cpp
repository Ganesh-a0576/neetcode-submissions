class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,ans=0;
        unordered_set<char> st;
        for(int r=0;r<n;r++){
            while(st.contains(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
