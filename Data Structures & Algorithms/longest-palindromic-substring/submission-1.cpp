class Solution {
    void sol(string &s,int i,int j,int &resl,int &resr){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            if(resr < (j-i+1)){
                resl=i;
                resr=(j-i+1);
            }
            i--;
            j++;
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.size(),resl=0,resr=1;
        for(int i=0;i<n;i++){
            sol(s,i,i,resl,resr);
            sol(s,i,i+1,resl,resr);
        }
        return s.substr(resl,resr);
    }
};
