class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        Map<Character,Character> m = new HashMap<>();
        m.put(')', '(');
        m.put(']', '[');
        m.put('}', '{');
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
                st.push(s.charAt(i));
            }else {
                if (!st.empty() && m.get(s.charAt(i)) == st.peek()) {
                    st.pop();
                }else {
                    return false;
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
}