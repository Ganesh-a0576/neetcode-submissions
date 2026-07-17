class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(const string& c:strs){
            s+=to_string(c.length())+'#'+c;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int d=s.find('#',i);
            int l=stoi(s.substr(i,d-i));
            ans.push_back(s.substr(d+1,l));
            i=d+1+l;
        }
        return ans;
    }
};
