/*
    簡單的題目
    題意為將text用空格去切割成好幾個單字
    再依據單字的長度來重組成新的text
    較短的單字排在前面 若是遇到一樣長度的單字則是依原本出現在text的相對位置來排先後
    然後組成的text第一個單字的頭要大寫
    後面單字的頭都小寫
    time complexity: O(nlog(n))
    space complexity: O(n)
*/
class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<string, int>> words;
        stringstream ss(text);
        string s;
        int i = 0;
        while(ss >> s){
            s[0] = tolower(s[0]);
            words.push_back({s, i});
            i++;
        }
        sort(words.begin(), words.end(), [](auto a, auto b){
            if(a.first.size() == b.first.size()){
                return a.second < b.second;
            }
            return a.first.size() < b.first.size();
        });
        string ans;
        for(int i = 0; i < words.size(); i++){
            ans += words[i].first + " ";
        }
        ans[0] = toupper(ans[0]);
        return  ans.erase(ans.find_last_not_of(" ")+1);;
    }
};