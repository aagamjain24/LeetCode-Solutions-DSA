class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int, vector<int> ,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        if(left.size() == right.size() + 2){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        else{
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */