class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> st;
    stack <int> temp;
    int curMin;
    MinStack() {
        curMin = INT_MAX;
    }
    
    void push(int x) {
        temp.push(curMin);
        st.push(x);
        if (curMin > x)
            curMin = x;
    }
    
    void pop() {
        curMin = temp.top();
        temp.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return curMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */