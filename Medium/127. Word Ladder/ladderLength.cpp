class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int l = beginWord.size();
        int step = 0;
        while(!q.empty()){
            step++;
            for(int size = q.size(); size > 0; size--){
                string w = q.front();
                q.pop();
                for(int i = 0; i < l; i++){
                    char c = w[i];
                    for(int j = 'a'; j <= 'z'; j++){
                        w[i] = j;
                        if(w == endWord){
                            return step + 1;
                        }
                        if(!dict.count(w)){
                            continue;
                        }
                        dict.erase(w);
                        q.push(w);
                    }
                    w[i] = c;
                }
            }
        }
        return 0;
    }
};