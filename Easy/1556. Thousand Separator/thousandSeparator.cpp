class Solution {
public:
    string thousandSeparator(int n) {
        /*
            這題概念很簡單，只要用一個count計算目前是3個位中的第幾個位
            當等於第三個位時就加上"."然後把count歸0重新計算
            time complexity: O(n)
            space complexity: O(1)
        */
        string ans = "";
        int count = 0;
        while(n){
            if(count == 3){
                ans += ".";
                count = 0;
            }
            int c = n % 10;
            n = n / 10;
            ans += to_string(c);
            count++;
        }
        reverse(ans.begin(), ans.end());
        return ans.empty()? "0" : ans; //檢查input: 0的狀態
    }
};