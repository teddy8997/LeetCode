/*
Time complexity: O(n) + O(nlogk)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto p : m){
            pq.emplace(-p.second, p.first);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};