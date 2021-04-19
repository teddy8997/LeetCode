class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int n : nums){
            q.push(n);
        }
        int ans = 0;
        for(int i = 0; i < k; i++){
            ans = q.top();
            q.pop();
        }
        return ans;
    }
};