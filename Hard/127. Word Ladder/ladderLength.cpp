/*
    這題主要就是使用BFS一位一位從a - z試一次

    time complexity: O(n * (26)^l) l = len(word), n = |wordList|
    space complexity: O(n)
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*建立一個字典方便查找那些要變換成的字*/
        unordered_set<string> dic(wordList.begin(), wordList.end());
        if(!dic.count(endWord)){
            return 0;
        }
                
        queue<string> q;
        q.push(beginWord);
        int l = beginWord.length();
        int step = 0;
        
        while(!q.empty()){
            step++;
            for(int size = q.size(); size > 0; size--){
                string s = q.front();
                q.pop();
                for(int i = 0; i < l; i++){
                    char ch = s[i];
                    for(int j = 'a'; j <= 'z'; j++){
                        s[i] = j;
                        if(s == endWord){ /*如果找到目標解救直接回傳step+1*/
                            return step+1;
                        }
                        if(!dic.count(s)){/*如果當前的字串不在字典中就直接往下一個字母替換*/
                            continue;
                        }
                        dic.erase(s);/*去除字典中變換過的字，因為只能用一次 用多次會繞遠路*/
                        q.push(s); /*將目前的字串存入queue*/
                    }
                    s[i] = ch; //將字串復原，使得能夠再改下一位
                }
            }
        }
        return 0;
    }
};