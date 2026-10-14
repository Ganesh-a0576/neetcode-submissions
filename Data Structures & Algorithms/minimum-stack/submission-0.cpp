class MinStack {
    private:
    stack<int> st,mst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        val=min(val,mst.empty()?val:mst.top());
        mst.push(val);
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};
