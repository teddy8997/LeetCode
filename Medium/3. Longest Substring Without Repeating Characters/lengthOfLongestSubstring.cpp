/*
     參考HUAHUA : https://zxi.mytechroad.com/blog/string/leetcode-3-longest-substring-without-repeating-characters/
     time complexity: O(n)
     space complexity: O(128)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> lastidx(128,-1);
        int i = 0;
        for(int j = 0; j < n; j++){
            i = max(i, lastidx[s[j]] + 1);
            ans = max(ans, j - i + 1);
            lastidx[s[j]] = j;
        }
        return ans;
    }
};