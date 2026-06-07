class MinStack {
public:
    // Amazon
    // Meta
    // nike
    // Google
    // Intuit
    // PayPal
    // Adobe
    // Salesforce

    stack<pair<int,int>> st ;
    MinStack() {
        
    }
    
    void push(int val) {
        if ( st.empty() ) {
            st.push({val , val}) ;
        }else {
            int minn = min ( val , st.top().second ) ;
            st.push({val , minn}) ;
        }
    }
    
    void pop() {
        st.pop() ;
    }
    
    int top() {
        return st.top().first ;
    }
    
    int getMin() {
        return st.top().second ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */