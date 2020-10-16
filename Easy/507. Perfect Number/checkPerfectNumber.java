class Solution {
    public boolean checkPerfectNumber(int num) {
        int n = (int)Math.sqrt(num);
        int sum = 0;
        if(num <= 1){
            return false;
        }
        for(int i = 1; i <= n; i++){
            if(num % i == 0){
                if(i == 1){
                    sum += 1;
                }else if (i * i == num){
                    sum += i;
                }else{
                    int d = num / i;
                    sum += (i + d);
                }
            }
        }
        if(sum == num){
            return true;
        }
        return false;
    }
}