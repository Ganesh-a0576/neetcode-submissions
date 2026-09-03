class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[s.size()]=true;
        for(int i=s.size()-1;i>=0;i--){
            for(auto &c:wordDict){
                if((i+c.length()) <=s.size() && (s.substr(i,c.length())==c)){
                    dp[i]=dp[i+c.length()];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }

};
