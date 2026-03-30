class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStk;
        stack<int> starStk;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openStk.push(i);
            } else if (s[i] == '*') {
                starStk.push(i);
            } else { 
                if (!openStk.empty()) {
                    openStk.pop();
                } else if (!starStk.empty()) {
                    starStk.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openStk.empty() && !starStk.empty()) {
            if (openStk.top() > starStk.top()) {
                return false;
            }
            openStk.pop();
            starStk.pop();
        }

        return openStk.empty();
    }
};