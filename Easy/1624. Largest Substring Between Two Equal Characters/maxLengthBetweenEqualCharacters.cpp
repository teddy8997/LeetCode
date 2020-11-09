class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        /*
            題目的意思就是要我們移除想個相同字符串後剩下子字串的最大長度
            所以我們移除最左邊出現的自香粽福串就可以了，因此用MAP來保存最左邊的位子
            當遍歷到相同的字符時維護更新最大長度ans
            time complexity: O(n)
            space complexity: O(n)
        */
        int ans = -1;
        unordered_map <char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.count(s[i])){
                ans = max(ans, i - m[s[i]] - 1);
            }else{
                m[s[i]] = i;
            }
        }
        return ans;
    }
};