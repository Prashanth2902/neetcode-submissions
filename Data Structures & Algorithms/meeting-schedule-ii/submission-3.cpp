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

    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int rooms = 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto i: intervals) {
            int start1 = i.start, end1 = i.end;
            while(!minheap.empty() && minheap.top() <= start1) minheap.pop();
            minheap.push(end1);
            rooms = max(rooms, (int)minheap.size());
        }
        return rooms;
    }
};
