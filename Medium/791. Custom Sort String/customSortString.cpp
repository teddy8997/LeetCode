class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> m;
        for(char c : T){//計算T字串中的每個字母的出現次數
            m[c]++;
        }
        string res = "";
        for(char c : S){//看S中的字母 在map中有出現幾次，將那些有出現的字母依這個字母的出現次數重複加入到res，加完後將次數歸0
            for(int i = 0; i < m[c]; i++){
                res += c;
            }
            m[c] = 0;
        }
        for(auto k : m){//將沒有規定順序的剩下字母(也就是沒出現在S字串中的字母)加入到res中
            if(k.second != 0){
                for(int i = 0; i < k.second; i++){
                    res += k.first;
                }
            }
        }
        return res;
    }
};