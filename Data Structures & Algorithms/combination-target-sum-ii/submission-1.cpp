class Solution {
public:

    void dfs(vector<int>& arr, int target, vector<vector<int>>& res, int i, vector<int>& subres, int currsum) {
        if(currsum == target) {
            res.push_back(subres);
            return;
        }
        if(currsum > target || i == arr.size()) return;
        subres.push_back(arr[i]);
        dfs(arr, target, res, i+1, subres, currsum + arr[i]);
        subres.pop_back();
        while(i+1 < arr.size() && arr[i] == arr[i+1]) i++;
        dfs(arr, target, res, i+1, subres, currsum);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> subres;
        sort(arr.begin(), arr.end());
        dfs(arr, target, res, 0, subres, 0);
        return res;
    }
};
