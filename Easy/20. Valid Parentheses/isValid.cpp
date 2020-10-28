class Solution {
public:
    bool isValid(string s) {
        /*
            time complexity: O(n)
            space complexity: O(n)
        */
        stack<char> st;
        for(char c : s){
            //遇到( [ { 就直接push
            if(c == '(' || c == '[' || c == '{'){ 
                st.push(c);
            //如果遇到 ) 然後stack中不是空的話就判斷stack的最上面的元素是不是(
            //不是的話就返回false 因為代表是這種情況(]...以此類推
            //是的話就把 ( pop出來代表完成配對
            }else if(c == ')' && !st.empty()){
                if(st.top() != '('){
                    return false;
                }
                st.pop();
            }else if(c == ']' && !st.empty()){
                if(st.top() != '['){
                    return false;
                }
                st.pop();
            }else if(c == '}' && !st.empty()){
                if(st.top() != '{') {
                    return false;
                }
                st.pop();
            }else{ //判斷輸入是 ')' 或是 ']' 或是'}'的這種情況
                return false;
            }     
        }
        //最後要檢查stack中是不是空的因為如果輸入是這種情況也是false
        //ex: [[[[...之類的 
        return st.empty(); 
    }
};