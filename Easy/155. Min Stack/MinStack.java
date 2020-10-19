public class MinStack {
    private Stack<Integer> S = new Stack<>();
    private Stack<Integer> minS = new Stack<>();
    
    public MinStack() {}  
    public void push(int x) {
        S.push(x);
        if (minS.isEmpty() || minS.peek() >= x){
            minS.push(x);
        } 
    }
    public void pop() {
        int x = S.pop();
        if(minS.peek() == x){
            minS.pop();
        } 
    }   
    public int top() {
        return S.peek();
    }  
    public int getMin() {
        return minS.peek();
    }
}