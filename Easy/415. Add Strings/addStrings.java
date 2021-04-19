class Solution {
    public String addStrings(String num1, String num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        int i = n1 - 1;
        int j = n2 - 1;
        int carry = 0;
        StringBuilder ans = new StringBuilder();
        while (i >= 0 || j >= 0) {
            int a = i >= 0? num1.charAt(i--) - '0': 0;
            int b = j >= 0? num2.charAt(j--) - '0': 0;
            int sum = a + b + carry;
            ans.append(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0) {
            ans.append(1);
        }
        return ans.reverse().toString();
    }
}