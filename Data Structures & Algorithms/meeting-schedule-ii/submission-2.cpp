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
    int minMeetingRooms(vector<Interval>& intervals) {

        if(intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> end_times;

        for(int i = 0; i < intervals.size(); i++) {
            if(!end_times.empty() && end_times.top() <= intervals[i].start) {
                end_times.pop();
            }
            end_times.push(intervals[i].end);
        }

        return (int)end_times.size();
        
    }
};
