
int countBalls(int lowLimit, int highLimit){
    int  m[1024] = {0};
    int ans = 0;
    for(int i = lowLimit; i <= highLimit; i++){
        int n = i;
        int sum = 0;
        while(n){
            sum += n % 10;
            n = n / 10;
        }
        m[sum]++;
        if(ans < m[sum]){
            ans = m[sum];
        }
    }
    return ans;
}