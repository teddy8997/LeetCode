class Solution {
public:
    int maximum69Number (int num) {
        //這題是要把num中一個6變成9 或是9變成6使num變成最大值
        //我們可以想要變成最大值一定是把第一個出現的6變成9會有最大值
        string s = to_string(num);
        bool first6 = false; //紀錄有沒有遇到第一個6
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(!first6 && s[i] == '6'){
                res += '9';
                first6 = true;
            }else{
                res += s[i];
            }
        }
        return stoi(res);
    }
};