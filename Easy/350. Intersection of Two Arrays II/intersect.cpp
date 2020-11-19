/*
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int a : nums1){
            m[a]++;
        }
        for(int b : nums2){
            if(m[b]-- > 0){
                ans.push_back(b);
            }
        }
        return ans;
    }
};