class Solution {
    List<List<Integer>> ans;
    public List<List<Integer>> combine(int n, int k) {
        ans = new ArrayList<List<Integer>>();
        List<Integer> track = new ArrayList<>();
        backtrack(n, k, 1, track);
        return ans;
    }
    private void backtrack(int n, int k, int start, List<Integer> track){
        if(k == track.size()){
            ans.add(new ArrayList<Integer>(track));
            return;
        }
        for(int i = start; i <= n; i++){
            track.add(i);
            backtrack(n, k, i + 1, track);
            track.remove(track.size() - 1);
        }
    }
}