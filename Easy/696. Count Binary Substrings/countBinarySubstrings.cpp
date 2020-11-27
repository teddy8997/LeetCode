/*
    分組數0或者1，例如"0110001111"，
    結果就是[1, 2, 3, 4]。 對於任意相鄰的0、1子字串，可能的substring的個數是1和0的長度的最小值。
    比如說，對於"0001111",，結果將是min(3, 4) = 3, ("01", "0011", "000111")。
    time complexity: O(n)
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int cur = 1;
        int pre = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                cur++;
            }else{
                ans += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        ans += min(cur, pre);
        return ans;
    }
};