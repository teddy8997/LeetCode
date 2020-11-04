class Solution {
public:
    int maxPower(string s) {
        /*
            很簡單的想法記錄前一個出現的字元並紀錄出現次數
            再和最大出現次數比較
            time complexity: O(n)
            space complexity: O(1)
        */
        int count = 0;
        int maxCount = 0;
        char pre = ' ';
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == pre){
                count++;
            }else{
                count = 1;
                pre = c;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};