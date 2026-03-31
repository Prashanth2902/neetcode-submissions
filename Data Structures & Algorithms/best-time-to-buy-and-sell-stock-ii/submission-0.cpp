class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int l = 0;
        for(int r=0;r<prices.size();r++) {
            if(prices[r] > prices[l]) {
                ans += prices[r] - prices[l];
                l++;
            } else {
                l = r;
            }
        }
        return ans;
    }
};