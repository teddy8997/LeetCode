/*
        題目限制的條件有+ - ( ) 及空格 我們就是需要處理這幾種條件
        需要一個stack以及一個變量sign來表示當前的符號 來輔助計算
        接著我們開始遍歷s字串
        首先若是數字的話，可能是有多位數所以要用While把數字都讀進來
        然後使用sign * num 來更新ans
        遇到加號 sign = 1
        遇到減號 sign = -1
        遇到( 就把ans跟sign push 到stack中，ans重置為0 sign重置為1
        遇到) 就將ans * stack頂端的符號, 頂端符號pop出來，ans 加上前面處理過的數字，然後再pop
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c >= '0'){
                int num = 0;
                while(i < n && s[i] >= '0'){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                ans += sign * num;
                i--;
            }else if(c == '+'){
                sign = 1;
            }else if(c == '-'){
                sign = -1;
            }else if(c == '('){
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }else if(c == ')'){
                ans *= st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};