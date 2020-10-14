class Solution {
    public int findPairs(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        Map<Integer, Integer> m = new HashMap<>();
        for(int num : nums){
            if(!m.containsKey(num)){
                m.put(num, 1);
            }else{
                m.put(num, m.get(num) + 1);
            }
            
        }
        for(Map.Entry<Integer, Integer> a : m.entrySet()){
            if(k == 0 && a.getValue() > 1){
                ans++;
            }
            if(k > 0 && m.containsKey(a.getKey() + k)){
                ans++;
            }
        }
        return ans;
    }
}