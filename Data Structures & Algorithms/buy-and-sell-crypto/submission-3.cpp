class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int res = 0;
        for(int r = 0 ; r < prices.size() ; r++) {
            if(prices[r] > prices[l]) {
                res = max(res, prices[r] - prices[l]);
            }
            while(prices[l] > prices[r]) l++;
        }
        return res;
    }
};
