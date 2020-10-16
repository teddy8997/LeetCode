class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n = sqrt(num);
        int sum = 0;
        if(num <= 1){
            return false;
        }
        for(int i = 1; i <= n; i++){
            if(num % i == 0){ //如果i能整除num,表示能夠找到factor
                if(i == 1){//特別處理1 * num = num這種情況，因為題目說排除自己本身 所以sum 只+1
                    sum += 1;
                }else if(i * i == num){//特別處理i * i = num這種情況,一樣的factor只加入一次
                    sum += i;
                }else{//剩下的情況就是兩個factor都加到sum中
                    int d = num / i;
                    sum += (d + i);
                }
            }
        }
        return sum == num;//最後比較和是否和num相同
    }
};