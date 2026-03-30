class MinStack {
public:

    stack<pair<int,int>> stk;

    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push({val, val});
        } else {
            int lowestVal = min(val, stk.top().second);
            stk.push({val, lowestVal});
        }
        
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
