/*
    如果依照題意用一個變數記錄所有的字串會因為太長而導致MLE
    所以我們要換另一種解法
    觀察一下字串，對於長度為L 重複M次的字串，我們要在L * M的字符串找到第K(從0開始)的字符的話
    就等於找L中第K % L個，知道這個規則之後我們可以由最長的長度反推回去求得第K個字符
    time complexity: O(N)
    space complexity: O(1)
*/

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long len = 0;
        int n = S.size();
        for(int i = 0; i < n; i++){
            if(isalpha(S[i])){
                len++;
            }else{
                len = len * (S[i] - '0');
            }
        }
        for(int i = n - 1; i >= 0; i--){
            K %= len;
            if(!K && isalpha(S[i])){
                return string(1, S[i]);
            }
            if(isdigit(S[i])){
                len /= S[i] - '0';
            }else{
                len--;
            }
        }
        return "";
    }
};