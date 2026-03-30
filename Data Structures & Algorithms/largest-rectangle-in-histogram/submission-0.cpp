class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0);
        int n = heights.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, h*w);
            }
            stk.push(i);
        }
        return ans;
    }
};