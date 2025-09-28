class MinStack {
public:
    using p = pair<int,int>;
    stack<p> st;

    MinStack() {}

    void push(int val) {
        int currMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currMin});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
