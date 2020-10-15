class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num != 0){ //如果num步為0就繼續迴圈
            if(num % 2 == 1){ //奇數減1 步驟加一
                num--;
                count++;
            }else if(num % 2 == 0){ //偶數直接除2 步驟加一
                num /= 2;
                count++;
            }
        }
        return count;
    }
};