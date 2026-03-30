class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(auto x: intervals) {
            int start = x[0];
            int end = x[1];
            int lastEnd = output.back()[1];
            if(start <= lastEnd) {
                output.back()[1] = max(end, lastEnd);
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }
};
