class Solution {
    public int[] frequencySort(int[] nums) {
        /*
            記住java如何寫comparator
        */
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            m.put(nums[i], m.getOrDefault(nums[i], 0) + 1);
        }
        Integer [] sorted = new Integer[nums.length];
        for(int i = 0; i < nums.length; i++){
            sorted[i] = nums[i];
        }
        Arrays.sort(sorted, new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                if(m.get(a) == m.get(b)){
                    return b - a;
                }
                return m.get(a) - m.get(b);
            }
        });
        for(int i = 0 ; i < nums.length; i++){
            nums[i] = sorted[i];
        }
        return nums;
    }
}