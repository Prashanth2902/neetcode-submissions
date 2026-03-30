class Solution {
public:

    int getDigitSquare(int n) {
        int res = 0;
        while(n > 0) {
            int temp = n%10;
            res += temp*temp;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> visit;
        int num = n;
        while(num != 1) {
            if(visit.count(num)) {
                return false;
            } else {
                visit.insert(num);
                num = getDigitSquare(num); 
            }
        }
        return true;
    }
};
