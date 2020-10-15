class Solution {
    public List<Integer> partitionLabels(String S) {
        List <Integer> s = new ArrayList();
        Map <Character, Integer> m = new HashMap<>();
        for(int i = 0; i < S.length(); i++){
            m.put(S.charAt(i), i);
        }
        int last = 0;
        int start = 0;
        for(int i = 0; i < S.length(); i ++){
            last = Math.max(last, m.get(S.charAt(i)));
            if(i == last){
                s.add(i - start + 1);
                start = i + 1;  
            }
        }
        return s;
    }
}