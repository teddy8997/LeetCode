/*
    先將word存入set中，再遍歷每個word的子串有沒有在set中有的話就去掉
    time complexity: O(n * l^2)
    space complexity: O(n * l)
*/
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for(string w : words){
            for(int i = w.size()-1; i > 0; i--){
                s.erase(w.substr(i));
            }
        }
        int ans = 0;
        for(auto w : s){
            ans += w.size() + 1;
        }
        return ans;
    }
};