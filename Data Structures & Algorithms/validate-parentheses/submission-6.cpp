class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                char top = stk.top();
                if ((top == '(' && c == ')') ||
                   (top == '{' && c == '}') ||
                   (top == '[' && c == ']')) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
