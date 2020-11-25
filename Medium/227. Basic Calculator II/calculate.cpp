/*
    
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long ans = 0;
        long num = 0;
        int n = s.size();
        char op = '+';
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == n-1){
                if(op == '+'){
                    st.push(num);
                }
                if(op == '-'){
                    st.push(-num);
                }
                if(op == '*' || op == '/'){
                    int tmp = (op == '*')? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};