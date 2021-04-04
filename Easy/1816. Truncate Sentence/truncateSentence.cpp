class Solution {
public:
    string truncateSentence(string s, int k) {
        vector<string> words;
        string tmp = "";
        istringstream ss(s);
        while (ss >> tmp) {
            words.push_back(tmp);
        }
        string ans = "";
        for (int i = 0; i < k; i++) {
           ans += words[i] + " ";
        }
        ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
};