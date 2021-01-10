/*
    x利用兩個map一個紀錄每個數字出現的次數
    一個紀錄每個數頭尾出現的位子，如果當前數字是第一次出現就更新頭尾位子，如果不是就更新尾位子
    然後先用一個for遍歷nums得到上面兩個資訊以及nums的degree
    第二個for則是用來找出出現次數為degree的數組
    計算首尾位子的差+1就是數組長度，由於出現次於為degree的數字不只有一個所以要遍歷count中所有的數，找到最小的即可
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int degree = 0;
        unordered_map<int, int> count;
        unordered_map<int, pair<int,int>> pos;
        for(int i = 0; i < n; i++){
            if(++count[nums[i]] == 1){
                pos[nums[i]] = {i, i};
            }else{
                pos[nums[i]].second = i;
            }
            degree = max(degree, count[nums[i]]);
        }
        
        for(auto m : count){
            if(degree == m.second){
                ans = min(ans, pos[m.first].second - pos[m.first].first + 1);
            }
        }
        return ans;
    }
};