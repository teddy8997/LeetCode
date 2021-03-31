class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
       if(st2.empty()){
           move();
       }
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty()){
            move();
        }
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;
    void move(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */