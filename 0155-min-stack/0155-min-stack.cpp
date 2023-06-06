class MinStack {
public:
    MinStack() {
       
    }
    stack<int> s1;
    stack<int> s2;
    
    
    void push(int val) {
        s2.push(val);
        if(s1.empty() || val <= s1.top()){
            s1.push(val);
        }
    }
    
    void pop() {

        if(s1.top() == s2.top()){
            s1.pop();
        }
        s2.pop();
    }
    
    int top() {
        return s2.top();
    }
    
    int getMin() {
        return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */