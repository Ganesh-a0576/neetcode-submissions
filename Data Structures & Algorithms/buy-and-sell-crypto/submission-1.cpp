class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pt=0,mx=prices[0];
        for(int i=1;i<prices.size();i++){
            int cur=prices[i]-mx;
            pt=max(pt,cur);
            mx=min(mx,prices[i]);
        }
        return pt;
    }
};
