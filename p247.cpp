class MyQueue {
public: 
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    

    void push(int x) {
        s1.push(x);
    }
    
    
    int pop() {
        int result = peek();
        s2.pop();
        return result;
    }
    
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());  s1.pop();
            }
        }
        return s2.top();
    }
    
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
