class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<char, int> window;
        while (right < n) {
            char c1 = s[right];
            window[c1]++;
            right++;
            while (window[c1] > 1) {
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};