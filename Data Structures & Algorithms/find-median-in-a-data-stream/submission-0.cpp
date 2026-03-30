class MedianFinder {
public:

    priority_queue<int> small_;
    priority_queue<int, vector<int>, greater<int>> large_;

    MedianFinder() {
        priority_queue<int> small_;
        priority_queue<int, vector<int>, greater<int>> large_;
    }
    
    void addNum(int num) {
        small_.push(num);
        if(!large_.empty() && small_.top() > large_.top()){
            large_.push(small_.top());
            small_.pop();
        }
        if(small_.size() > large_.size() + 1) {
            large_.push(small_.top());
            small_.pop();
        }
        if(large_.size() > small_.size() + 1) {
            small_.push(large_.top());
            large_.pop();
        }
    }
    
    double findMedian() {
        if(small_.size() > large_.size()) return small_.top();
        else if (small_.size() < large_.size()) return large_.top();
        else {
            return (small_.top() + large_.top()) / 2.0;
        }
    }
};
