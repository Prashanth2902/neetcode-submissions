class Solution {
public:

    long reverseNum(int n, long res) {
        if(n == 0) return res;
        res = res * 10 + n % 10;
        return reverseNum(n/10, res);
    }

    int reverse(int x) {
        long res = reverseNum(abs(x), 0) * (x < 0 ? -1 : 1);
        if(res < INT_MIN || res > INT_MAX) return 0;
        return (int) res;
    }
};
