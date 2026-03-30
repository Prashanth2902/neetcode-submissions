class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int last = intervals[0][1];
        for(int i=1;i<intervals.size();i++) {
            if(last > intervals[i][0]) {
                ans++;
                last = min(intervals[i][1], last);
            } else {
                last = intervals[i][1];
            }
        }
        return ans;
    }
};
