class Solution {
public:
    bool checkRecord(string s) {
        int Acount = 0;
        int Lcount = 0;
        for(char c : s){
            if(c == 'A'){
                Acount++;
            }
            if(c == 'L'){
                Lcount++;
            }else{
                Lcount = 0;
            }
            if(Acount > 1 || Lcount > 2){
                return false;
            }
        }
        return true;
    }
};