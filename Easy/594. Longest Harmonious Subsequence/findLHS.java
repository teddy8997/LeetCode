class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        int ans = 0;
        for(int n : nums){
            m.put(n, m.getOrDefault(n, 0) + 1);
            if(m.containsKey(n - 1) &&  m.containsKey(n + 1)){
                ans = Math.max(ans, m.get(n) + Math.max(m.get(n - 1), m.get(n + 1)));
            }else if(m.containsKey(n - 1) && !m.containsKey(n + 1)){
                ans = Math.max(ans, m.get(n) + m.get(n - 1));
            }else if(!m.containsKey(n - 1) && m.containsKey(n + 1)){
                ans = Math.max(ans, m.get(n) + m.get(n + 1));
            }
        }
        return ans;
    }
}