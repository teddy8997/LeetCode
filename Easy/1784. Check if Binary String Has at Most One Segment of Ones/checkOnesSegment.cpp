/*
    題目說s[0]一定是1，且只能有一個連續為1個區段，所以我們倆倆比較，如果有1->0又0->1狀態變化2次就代表不符合題意返回false
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    bool checkOnesSegment(string s) {
        int change = 0;
        for(int i = 1; i < s.size(); i++){     
            if(s[i] != s[i-1]){
                change++;
            }
            if(change == 2){
                return false;
            }
        }
        return true;
    }
};