class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set <string> s;
        int i = 0;
        while(i < word.size()){
            if(!isdigit(word[i])){
                i++;
                continue;
            }
            string tmp = "";
            while(i < word.size() && isdigit(word[i])){
                tmp += word[i];
                i++;
            }
            int j = 0;
            while(j < tmp.size() && tmp[j] == '0'){
                j++;
            }
            tmp = tmp.substr(j);
            s.insert(tmp);
        }
        return s.size();
    }
};