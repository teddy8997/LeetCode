/*
    參考: https://github.com/labuladong/fucking-algorithm/blob/master/%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E5%88%A4%E5%AE%9A%E5%AD%90%E5%BA%8F%E5%88%97.md

*/
class Solution {
    public boolean isSubsequence(String s, String t) {
        int m = s.length();
        int n = t.length();
        ArrayList<Integer>[] index = new ArrayList[256];
        for(int i = 0; i < n; i++){
            char c = t.charAt(i);
            if(index[c] == null){
                index[c] = new ArrayList<>();
            }
            index[c].add(i);
        }
        int j = 0;
        for(int i = 0; i < m; i++){
            char c = s.charAt(i);
            if(index[c] == null){
                return false;
            }
            int pos = left_bound(index[c], j);
            if(pos == index[c].size()){
                return false;
            }
            j = index[c].get(pos) + 1;
        }
        return true;
    }
    private int left_bound(ArrayList<Integer> arr, int tar){
        int l = 0;
        int r = arr.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(tar > arr.get(m)){
                l = m + 1;
            }else if(tar < arr.get(m)){
                r = m - 1;
            }else if(tar == arr.get(m)){
                r = m - 1;
            }  
        }
        return l;
    }
}