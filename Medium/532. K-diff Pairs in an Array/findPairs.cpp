class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int ans = 0;
        //計算每個數字出現的個數存在MAP中
        for(int num : nums){
            m[num]++;
        }
        //遍歷map中的元素
        for(auto a : m){
            //若是差值要求的是k = 0 且 元素出現次數大於2,ans++;
            if(k == 0 && a.second > 1){
                ans++;
            }
            //若差值要求k > 0 且 查找MAP中有無當前這個數+k存在,若是有則ans++
            if(k > 0 && m.count(a.first + k)){
                ans++;
            }
        }
        return ans;
    }
};