class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alpha(26, 0);
        for (char c : sentence) {
            alpha[c - 'a']++;
        }
        for (int n : alpha) {
            if (n == 0) {
                return false;
            }
        }
        return true;
    }
};