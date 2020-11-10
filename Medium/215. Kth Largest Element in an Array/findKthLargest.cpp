class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
            法一:
            利用priority_queue自動排序的性質
            time complexity: O(log n)
            space complexity: O(1);
        */
        /*
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i = 0; i < k-1; i++){
            pq.pop();
        }
        return pq.top();
        */
        /*
            法二
            time complexity: O(n*log(n))
            space complexity: O(1);
        */
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};