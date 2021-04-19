class Solution {
    public String largestNumber(int[] nums) {
        if (nums.length == 0 || nums == null) {
            return "";
        }
        String [] strs = new String [nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = nums[i] + "";
        }
        
        Arrays.sort(strs, new Comparator<String>() {
            public int compare(String a, String b) {
                String s1 = a + b;
                String s2 = b + a;
                return s1.compareTo(s2);
                
            }
        });
        
        String ans = "";
        for (int i = 0; i < strs.length; i++) {
            ans = strs[i] + ans;
        }
        return ans.charAt(0) == '0'? "0" : ans;  
    }
}