class Solution {
public:
    string multiply(string num1, string num2) {
        /*
            例如: num1 長度為m, num2 長度為n
            兩數相乘位數不會超過m+n
            而num1 num2中任意位置的數字相乘得到的位置會是i + j 以及 i + j +1
        */
        string res = "";
        int m = num1.size();
        int n = num2.size();
        vector<int> vals(m+n,0);
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        for(int val : vals){
            if(!res.empty() || val != 0){
                res.push_back(val + '0');
            }
        }
        return res.empty()? "0" : res;
    }
};