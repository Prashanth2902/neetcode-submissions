class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int ans = -1;
        while (left <= right) {
            int l = right - left;
            int b = min(arr[left], arr[right]);
            ans = max(ans, l*b);
            if(arr[left] > arr[right]) right--;
            else left++;
        }
        return ans;
    }
};
