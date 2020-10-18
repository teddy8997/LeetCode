class Solution {
  public boolean backspaceCompare(String S, String T) {
      return check(S).equals(check(T));
  }
  private String check(String s) {
      StringBuilder sb = new StringBuilder();
      
      for (char c : s.toCharArray()) {
        if (c == '#') {
          if (sb.length() > 0)
            sb.deleteCharAt(sb.length() - 1);
          }else{
            sb.append(c);
          }
        }
      return sb.toString();
  }
}