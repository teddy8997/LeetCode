/*
    依據題意要我們找出有幾層資料夾
    所以我們只要專注在紀錄有幾層深度就好
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string log : logs){
            if(log == "../"){
                ans = max(ans - 1, 0);
            }else if(log != "./"){
                ans++;
            }
        }
        return ans;
    }
};