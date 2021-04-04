class Solution {
public:
    int longestValidParentheses(string s) {
        int start = 0;
        int n = s.size();
        int ans = 0;
        stack<int> tmp;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                tmp.push(i);
            }else if (s[i] == ')') {
                if (tmp.empty()) {
                    start = i + 1;
                }else {
                    tmp.pop();
                    if (tmp.empty()) {
                        ans = max(ans, i - start + 1);
                    }else {
                        ans = max(ans, i - tmp.top());
                    }
                }
            }
        }
        return ans;
    }
};