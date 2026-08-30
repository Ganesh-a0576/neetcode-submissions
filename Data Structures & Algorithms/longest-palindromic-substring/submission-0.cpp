class Solution {
public:
    string longestPalindrome(string s) {
        int resl=0,resr=0;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(resr< (j-i+1)){
                        resl=i;
                        resr=j-i+1;
                    }
                }
            }
        }
        return s.substr(resl,resr);
    }
};
