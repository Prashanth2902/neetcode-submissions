class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0) {
            exp = -exp;
            x = 1/x;
        }
        double res = 1;
        double cp = x;
        while(exp) {
            if(exp&1) res *= cp;
            cp *= cp;
            exp /= 2;
        }
        return res;
    }
};