class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int currSum = 0;
        int res = 0;
        for(int i=0;i<k-1;i++) {
            currSum += arr[i];
        }

        for(int i=0;i<=arr.size() - k;i++) {
            currSum += arr[i + k-1];
            if((currSum/k) >= threshold) res++;
            currSum -= arr[i];
        }


        return res;
    }
};