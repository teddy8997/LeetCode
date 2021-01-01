/*
    主要就是將所有單字放進hash table然後採用BFS
    先將所有長度為1的單字放入queue.然後進行循環每次從最前面取出一個元素出來
    如果長度大於現在維護的最大值maxLen就更新結果ans以及maxLen，如果長度剛好相等則是要取字母順序比較小的字串
    接下來我們就是從a遍歷到z,如果存在字典中就加入queue中等待下次循環，使用完後記得要再pop_back()回來回復狀態
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        int maxLen = 0;
        unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        for(string word : words){
            if(word.size() == 1){
                q.push(word);
            }
        }
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            if(tmp.size() > maxLen){
                maxLen = tmp.size();
                ans = tmp;
            }else if(tmp.size() == maxLen){
                ans = min(ans, tmp);
            }
            for(char c = 'a'; c <= 'z'; c++){
                tmp.push_back(c);
                if(s.count(tmp)){
                    q.push(tmp);
                }
                tmp.pop_back();
            }
        }
        return ans;
    }
};