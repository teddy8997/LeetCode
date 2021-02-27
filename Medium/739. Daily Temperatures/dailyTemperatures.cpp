class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        stack<pair<int, int>> s;
        for(int i = T.size() - 1; i >= 0; i--){
            while(!s.empty() && s.top().second <= T[i]){
                s.pop();
            }
            ans[i] = s.empty()? 0 : s.top().first - i;
            s.push({i, T[i]});
        }
        return ans;
    }
};