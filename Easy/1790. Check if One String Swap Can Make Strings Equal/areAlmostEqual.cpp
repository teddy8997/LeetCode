/*
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        set<char> s;
        for(char c : s1){
            s.insert(c);
        }
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s.count(s2[i]) && s1[i] != s2[i]){
                count++;
            }
        }
        return count == 2? true : false;
    }
};