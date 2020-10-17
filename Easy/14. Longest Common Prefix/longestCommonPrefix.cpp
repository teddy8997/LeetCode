class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string comm = "";
        if(strs.empty()){ //如果字串是空的就直接回傳空的
            return comm;
        }
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                //如果i的字串長度已經超過另一個字串的長度或是另一個字串的字符和第一個字串的字符不相同
                if(i >= strs[j].size() || strs[j][i] != c){ 
                    return comm; //直接回傳目前存的共同字符串
                }
            }
            comm.push_back(c);
        }
        return comm;
    }
};