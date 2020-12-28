/*
    這題就照著題目所說的操作流程使用stack的先進後出特性來完成
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<string> st;
        for(string s : ops){
            if(s == "C"){
                st.pop();
            }else if(s == "D"){
                string n = st.top();
                int num = stoi(n);
                st.push(to_string(num*2));
            }else if(s == "+"){
                string n1 = st.top();
                int num1 = stoi(n1);
                st.pop();
                string n2 = st.top();
                int num2 = stoi(n2);
                st.pop();
                
                st.push(n2);
                st.push(n1);
                st.push(to_string(num1 + num2));
            }else{
                st.push(s);
            }
        }
        int ans = 0;
        while(!st.empty()){
            string numSt = st.top();
            ans += stoi(numSt);
            st.pop();
        }
        return ans;
    }
};