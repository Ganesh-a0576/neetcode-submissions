class Solution {
    int sol(string s,int i,int j){
        int ans=0;
        while(i>=0 && j< s.size() && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
        return ans;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=sol(s,i,i);
            ans+=sol(s,i,i+1);
        }
        return ans;
    }
};
