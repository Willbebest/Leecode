class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i = Q.size() - 1; i >= 1; i--) {
            Q.push(Q.front());
            Q.pop();
        }
        int ret = 0;
        if(Q.size() != 0) {
            ret = Q.front();
            Q.pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return Q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return  Q.empty();
    }
private:
    queue<int> Q;
};