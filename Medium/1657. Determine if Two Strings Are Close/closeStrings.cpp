/*
    如果兩個string是相近的要滿足以下特點
    (1) 兩個字串一樣長度
    (2) 有一樣的char set
    (3) 出現的字母的次數 排序後內容一樣
    
    time complexity: O(nlogn)
    space complexity: O(1)
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1 != len2){
            return false;
        }
        vector<int> f1(128), f2(128);
        vector<int> s1(128), s2(128);
        for(char c : word1){
            f1[c]++;
            s1[c] = 1;
        }
        for(char c : word2){
            f2[c]++;
            s2[c] = 1;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2 && s1 == s2;
    }
};