class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int count = 0;
        List<Pair<Integer, Integer>> lt = new ArrayList<>();
        int [] ans = new int [k];
        for(int i = 0; i < mat.length; i++){
            count = 0;
            for(int j = 0; j < mat[0].length; j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            lt.add(new Pair(i, count));
        }
        lt.sort(new Comparator<Pair<Integer, Integer>>(){
            @Override
            public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b){
                if(a.getValue() == b.getValue()){
                    return a.getKey() - b.getKey();
                }
                return a.getValue() - b.getValue();
            }
        });
        for(int i = 0; i < k; i++){
            ans[i] = lt.get(i).getKey();
        }
        return ans;
    }
    
}