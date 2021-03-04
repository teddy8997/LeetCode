/*
    參考: https://zxi.mytechroad.com/blog/leetcode/leetcode-139-word-break/
    time complexity: O(n^2)
    space complexity: O(n^2)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sd(wordDict.begin(), wordDict.end());
        return wordB(s, sd);
    }
private:
    unordered_map<string, bool> m;
    bool wordB(string &s, unordered_set<string> &sd){
        if(m.count(s)){
            return m[s];
        }
        if(sd.count(s)){
            m[s] = true;
            return true;
        }
        for(int i = 1; i < s.size(); i++){
            string left = s.substr(0, i);
            string right = s.substr(i);
            if(sd.count(left) && wordB(right, sd)){
                m[s] = true;
                return true;
            }
        }
        m[s] = false;
        return false;  
    }
};