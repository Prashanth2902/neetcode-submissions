class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0];
        int currMin = 0, currMax = 0;
        int total = 0;

        for(int x: nums) {
            currMax = max(currMax, 0);
            currMin = min(currMin, 0);

            currMax += x;
            currMin += x;

            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);

            total += x;
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};