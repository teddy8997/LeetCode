class Solution {
    List<List<Integer>> ans;
    public List<List<Integer>> permute(int[] nums) {
        ans = new ArrayList<List<Integer>>();
        List<Integer> track = new ArrayList<>();
        backtrack(nums, track);
        return ans;
    }
    private void backtrack(int[] nums, List<Integer> track){
        if(track.size() == nums.length){
            ans.add(new ArrayList<Integer>(track));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(track.contains(nums[i])){
                continue;
            }
            track.add(nums[i]);
            backtrack(nums, track);
            track.remove(track.size() - 1);
        }
    }
}