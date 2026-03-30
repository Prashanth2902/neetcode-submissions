class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int l = 0;
        for(int r = 0; r < prices.size(); r++) {
            int currVal = prices[r];
            while(prices[l] > currVal) {
                l++;
            }
            res = max(res, prices[r] - prices[l]);
        }
        return res;
    }
};
