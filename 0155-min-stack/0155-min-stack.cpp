class MinStack {
public:
stack<pair<int,int>> s;

    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            int mini=val;
            s.push({val,mini});
        } else{
            s.push({val,min(s.top().second,val)});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
       return s.top().first;
    }
    
    int getMin() {
        int val=s.top().second;
        return val;
        
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