class MedianFinder {
public:

    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        if(small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        if(large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) {
            return small.top();
        } else if(small.size() < large.size()) {
            return large.top();
        } else {
            return (small.top() + large.top()) / 2.0;
        }
    }
};
