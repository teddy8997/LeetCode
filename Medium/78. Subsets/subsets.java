class Solution {  
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> track = new ArrayList<>();
        backtrack(nums, 0, track, ans);
        return ans;
    }
    private void backtrack(int [] nums, int start, List<Integer> track, List<List<Integer>> ans){
        ans.add(new ArrayList<Integer>(track));
        for(int i = start; i < nums.length; i++){
            track.add(nums[i]);
            backtrack(nums, i + 1, track, ans);
            track.remove(track.size() - 1);
        }
    }
}