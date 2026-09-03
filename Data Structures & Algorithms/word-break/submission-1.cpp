class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[s.size()]=true;
        for(int i=s.size()-1;i>=0;i--){
            for(const auto&c:wordDict){
                if((i+c.size()<=s.size()) && s.substr(i,c.size())==c){
                    dp[i]=dp[i+c.size()];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};
