class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //將數組nums1及nums2利用set去重複數字
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> ans;
        //再找num2中存在於nums1的數
        for(auto num : s2){
            if(s1.count(num)){
                ans.push_back(num);
            }
        }
        return ans;
    }
};