class MinStack {
public:
    MinStack() {
        
    }
    
    stack<int> minStack;
    stack<int> mainStack;

    void push(int val) {
        if(minStack.empty())
            minStack.push(val);
        else
            minStack.push(std::min(minStack.top(),val));

        mainStack.push(val);
    }
    
    void pop() {
        
        if(!minStack.empty())
            minStack.pop();

        if(!mainStack.empty())        
            mainStack.pop();
    }
    
    int top() {
       return mainStack.top();
    }
    
    int getMin() {
        if(!minStack.empty())
            return minStack.top();
    }
};
