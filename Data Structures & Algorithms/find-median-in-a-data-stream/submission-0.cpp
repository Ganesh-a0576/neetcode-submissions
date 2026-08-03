class MedianFinder {
    private:
    vector<int> ans;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ans.push_back(num);
    }
    
    double findMedian() {
        sort(ans.begin(),ans.end());
        int n=ans.size();
        return (n&1)?ans[n/2]:(ans[n/2]+ans[n/2-1])/2.0;
    }
};
