class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int len1 = num1.size();
        int len2 = num2.size();
        int i = len1 - 1;
        int j = len2 - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int a = i >= 0? num1[i--] - '0' : 0;
            int b = j >= 0? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            ans.insert(ans.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry == 0? ans : "1" + ans;
    }
};