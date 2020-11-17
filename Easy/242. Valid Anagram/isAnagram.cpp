/*
    法一: 利用Map紀錄s字串出現過的字母以及次數，再遍歷t字串去判斷字母有沒有存在map中以及次數是不是0
    time complexity: O(n)
    space complexity: O(n)
*/
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> mS;
        for(char c : s){
            mS[c]++;
        }
        for(char c : t){
            if(mS.count(c) && mS[c] != 0){
                mS[c]--;
            }else{
                return false;
            }
        }
        return true;
    }
};
*/
/*
    法二: 將s以及t字串分別排序，最後再比較兩個字串是否相等
    time complexity: O(nlogn)
    space complexity: O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};