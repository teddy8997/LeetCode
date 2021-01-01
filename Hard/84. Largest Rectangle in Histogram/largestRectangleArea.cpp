/*
    題目要我們找出可以構成面積最大的矩形是多少
    使用一個stack來存那些依index順序訪問遇到更高的bar的index
    當遇到較矮的bar就pop stack中最高的bar然後使用這個當作瓶頸來計算面積
    參考:https://zxi.mytechroad.com/blog/stack/leetcode-84-largest-rectangle-in-histogram/
    
    time complexity: O(n)
    space complexity: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int i = 0;
        int ans = 0;
        while(i < n){
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i);
                i++;
            }else{
                int h = heights[s.top()];
                s.pop();
                int w = s.empty()? i : i - s.top() - 1;
                ans = max(ans, w * h);
            }
        }
        return ans;
    }
};