/*
    先計算每個數字出現的次數後，由小到大排序，優先移除最低出現次數的數字。
    time complexity: O(nlogn)
    space complexity: O(n)
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> f;
        for(int n : arr){
            f[n]++;
        }
        vector<int> m;
        for(auto [x, fq] : f){
            m.push_back(fq);
        }
        sort(m.begin(), m.end());
        int ans = m.size();
        int i = 0;
        while(k){
            if(--m[i] == 0){
                i++;
                ans--;
            }
            k--;
        }
        return ans;
    }
};