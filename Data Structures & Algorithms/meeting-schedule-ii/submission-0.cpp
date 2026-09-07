/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& a) {
        vector<pair<int,int>> pr;
        for(auto i:a){
            pr.push_back({i.start,1});
            pr.push_back({i.end,-1});
        }
        sort(pr.begin(),pr.end(),[](auto i,auto j){
            return i.first==j.first ? i.second < j.second : i.first < j.first; 
            });
        int cnt=0,ans=0;
        for(auto i:pr){
            cnt+=i.second;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
