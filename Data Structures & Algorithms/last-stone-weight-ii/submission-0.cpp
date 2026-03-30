class Solution {
public:

    int dfs(int i, int total, vector<int>& stones, int target, int stoneSum, vector<vector<int>>& cache) {
        if(total >= target || i == stones.size()) {
            return abs(total - (stoneSum - total));
        }
        if(cache[i][total] != -1) return cache[i][total];
        cache[i][total] = min(dfs(i+1,total,stones,target,stoneSum,cache), dfs(i+1,total+stones[i],stones,target,stoneSum,cache));
        return cache[i][total];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stoneSum + 1) / 2;
        vector<vector<int>> cache(stones.size(), vector<int>(target+1, -1));
        return dfs(0, 0, stones, target, stoneSum, cache);
    }
};