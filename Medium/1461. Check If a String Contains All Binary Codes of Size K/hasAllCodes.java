/*
    參考https://blog.csdn.net/weixin_49991368/article/details/114777643
    使用sliding window
*/
class Solution {
    public boolean hasAllCodes(String s, int k) {
        if(k > s.length()){
            return false;
        }
        HashSet<String> st = new HashSet<>();
        StringBuilder str = new StringBuilder(s.substring(0,k));
        st.add(str.toString());
        for(int i = k; i < s.length(); i++){
            str.deleteCharAt(0);
            str.append(s.charAt(i));
            st.add(str.toString());
        }
        return st.size() == Math.pow(2,k);
    }
}