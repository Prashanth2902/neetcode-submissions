class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto x: s) {
            if(x == '(' || x == '[' || x == '{') stk.push(x);
            else {
                if(stk.empty()) return false;
                char topVal = stk.top();
                if(topVal == '(' && x != ')') return false;
                if(topVal == '[' && x != ']') return false;
                if(topVal == '{' && x != '}') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
