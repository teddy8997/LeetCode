/*

*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int low = INT_MAX;
        for(int n : nums){
            n = n % 2 == 0? n : n * 2;
            q.push(n);
            low = min(low, n);
        }
        int ans = q.top() - low;
        while(q.top() % 2 == 0){
            int x = q.top();
            q.pop();
            q.push(x / 2);
            low = min(low, x / 2);
            ans = min(ans, q.top() - low);
        }
        return ans;
    }
};