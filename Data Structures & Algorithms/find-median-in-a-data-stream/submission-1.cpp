class MedianFinder {
    private:
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<>> mn;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mx.push(num);
        mn.push(mx.top());
        mx.pop();
        if(mn.size()>mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()>mn.size()) return mx.top();
        else return ((mx.top()+mn.top())/2.0);
    }
};
