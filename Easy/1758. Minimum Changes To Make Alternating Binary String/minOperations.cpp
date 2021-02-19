class Solution {
public:
    int minOperations(string s) {
        int x = 0;
        int y = 0;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0 && s[i] == '1' || i % 2 == 1 && s[i] == '0'){
                x++;
            }else if(i % 2 == 0 && s[i] == '0' || i % 2 == 1 && s[i] == '1'){
                y++;
            }
        }
        return min(s.size() - x, s.size() - y);
    }
};