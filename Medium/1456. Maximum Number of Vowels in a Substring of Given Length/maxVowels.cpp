/*
    這題想法就是sliding window 我們創一個128大小的vector當作map
    並分別在母音的位置設為1
    一個一個檢查每個是不是母音 若是i超過k的長度就要看最左邊的字母是不是母音要把它加上的次數減掉
    Time complexity: O(n)
    Space complexity: O(1)


*/
class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> v(128);
        v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1; 
        int total = 0;
        int maxCount = 0;
        for(int i = 1; i <= s.size(); i++){
            total += v[s[i-1]];
            if(i >= k){
                maxCount = max(maxCount, total);
                total -= v[s[i-k]];
            }
        }
        return maxCount;
    }
};