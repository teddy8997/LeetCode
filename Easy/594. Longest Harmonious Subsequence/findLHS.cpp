/*
    依照nums順序從左到右訪問，並利用一個map紀錄目前這個數的出現次數
    每當訪問到一個數時先將m中這個數的次數+1
    然後用兩個變數h及l分別比這個數大1的數出現過幾次，然後比這個數少1的數出現過幾次
    接下來就是比較當前的數出現的次數加上看h還是l出現的次數多，來和ans比來做更新
    如果h多的話代表當前的數是當最小值
    如果l多的話代表當前的數是當最大值
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int n : nums){
            m[n]++;
            int l = m[n - 1];
            int h = m[n + 1];
            if(l || h){
                ans = max(ans, m[n] + max(l,h));
            }
        }
        return ans;
    }
};