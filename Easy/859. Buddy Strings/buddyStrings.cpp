class Solution {
public:
    bool buddyStrings(string A, string B) {
        //如果AB兩個字串長度不一定代表怎換一定都不一樣，回傳false
        if(A.size() != B.size()){
            return false;
        }
        //如果A和B字串內容相等 而且 A去掉重複的字元後 長度若是比A還短 代表有A重複的字元也就是可以換成B
        //EX: A = "aa" B = " aa"
        if(A == B && unordered_set<char>(A.begin(), A.end()).size() < A.size()){
            return true;
        }
        //紀錄A B 字元相異的位子
        vector<int> diff;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i]){
                diff.push_back(i);
            }
        }
        //如果有兩個相異字元 而且A的第一個相異字元和B的第二個相異字元相同 且A的第二個相異字元和B的第一個相異字元相同 就代表可交換
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};