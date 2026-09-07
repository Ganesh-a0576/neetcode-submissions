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
    bool canAttendMeetings(vector<Interval>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),[](auto& a,auto& b){
            return a.start < b.start;
        });
        for(int i=1;i<n;i++){
            if(a[i].start < a[i-1].end) return false;
        }
        return true;
    }
};
