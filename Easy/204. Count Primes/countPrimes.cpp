class Solution {
public:
    int countPrimes(int n) {
        if(n < 3){
            return 0;
        }
        vector<unsigned char> f(n, 1);
        f[0] = f[1] = 0;
        for(long i = 2; i <= sqrt(n); i++){
            if(!f[i]){
               continue; 
            }
            for(long j = i * i; j <= n; j += i){
                f[j] = 0;
            }
        }
        int ans = accumulate(f.begin(), f.end(), 0);
        return ans;
    }
};