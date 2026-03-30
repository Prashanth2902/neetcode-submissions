class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        stack<pair<int,int>> stk;
        for(int i=0;i<arr.size();i++){
            int t = arr[i];
            while(!stk.empty() && t > stk.top().first) {
                auto pairMap = stk.top();
                stk.pop();
                res[pairMap.second] = i - pairMap.second;
            }
            stk.push({t, i});
        }
        return res;
    }
};
