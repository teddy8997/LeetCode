class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        int r = 0;
        while(r < nums.size()){
           if(st.size() >= k){
               st.erase(st.find(nums[r - k]));
           }
            st.insert(nums[r]);
            if(r >= k - 1){ //window大小是k
                ans.push_back(*st.rbegin());
            }
            r++;
        }
        return ans;   
    }
};