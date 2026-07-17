class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest=0;
        for(int num:s){
            if(!s.count(num-1)){
                int cur=num,len=1;
                while(s.count(cur+1)){
                    cur++;
                    len++;
                }
                longest=max(longest,len);
            }
        }
        return longest;
    }
};
