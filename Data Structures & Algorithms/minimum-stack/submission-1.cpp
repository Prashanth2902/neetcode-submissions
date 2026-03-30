class MinStack {
private:
    stack<int> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        stack<int> getMin;
        int minVal = stk.top();
        while(stk.size()) {
            minVal = min(minVal, stk.top());
            getMin.push(stk.top());
            stk.pop();
        }
        while(getMin.size()) {
            stk.push(getMin.top());
            getMin.pop();
        }
        return minVal;
    }
};
