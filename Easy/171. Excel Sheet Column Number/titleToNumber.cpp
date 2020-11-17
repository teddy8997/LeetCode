class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int exp = 0;
        for(int i = s.size()-1; i >= 0; i--){
            int a = s[i] - 64;
            a = a * pow(26, exp);
            exp++;
            sum += a;
        }
        return sum;
    }
};