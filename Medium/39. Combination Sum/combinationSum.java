class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        List<Integer> cur = new ArrayList<>();
        findSum(candidates, target, ans, cur, 0);
        return ans;
    }
    public void findSum(int[] candidates, int target, List<List<Integer>> ans, List<Integer> cur, int d){
        if(target == 0){
            ans.add(new ArrayList<Integer>(cur));
            return;
        }
        for(int i = d; i < candidates.length; i++){
            if(candidates[i] > target){
                break;
            }
            cur.add(candidates[i]);
            findSum(candidates, target - candidates[i], ans, cur, i);
            cur.remove(cur.size()-1);
        }
        return;
    }
}