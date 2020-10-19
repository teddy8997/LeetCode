class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        //直接先將x push到S stack
        //然後檢查紀錄當前最小數字的minS stack是否是空的或是最上面的元素比要加入的大
        //如果是此情形就將這個數字push到minS中
        S.push(x);
        if(minS.empty() || minS.top() >= x){
            minS.push(x);
        }
    }
    
    void pop() {
        if(!S.empty()){
            //pop時要注意要POP的那個值是不是最小值如果是的話minS也要跟著pop才行
            if(S.top() == minS.top()){
                S.pop();
                minS.pop();
            }else{
                S.pop();
            }
        }    
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minS.top();
    }
private:
    stack<int> S;
    //使用另一個stack來記錄當前出現的最小數字
    stack<int> minS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */