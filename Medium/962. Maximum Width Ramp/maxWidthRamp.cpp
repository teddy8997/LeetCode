
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
       stack<int> s;
        for(int i = 0; i < A.size(); i++){
            if(s.empty() || A[i] < A[s.top()]){
                s.push(i);
            }
        }
        int ans = 0;
        for(int i = A.size() - 1; i >= 0; i--){
            while(!s.empty() && A[i] >= A[s.top()]){
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};