class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int d = 0;
        //題目要我們找最深括號深度,所以我們只需要關注'('以及')'
        //使用一個變數d來記錄深度變化，遇到'('深度就+1,遇到')'深度就-1
        //然後使用一個變數ans來比較目前深度和之前深度相比有沒有更深(也就是d有無大於ans)
        //有的話就更新ans中的值
        for(char c : s){
            if(c == '('){
                d++;
                ans = max(ans, d);
            }else if(c == ')'){
                d--;
            }
        }
        return ans;
    }
};