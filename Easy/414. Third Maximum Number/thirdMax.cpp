class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        priority_queue<int> pq;
        for(int num : s){
            pq.push(num);
        }
        if(s.size() <= 2){
            return pq.top();
        }
        pq.pop();
        pq.pop();
        return pq.top();
    }
};