class Solution {
    public boolean buddyStrings(String A, String B) {
        if(A.length() != B.length()){
            return false;
        }
        Set<Character> sA = new HashSet<>();
        for(int i = 0; i < A.length(); i++){
            sA.add(A.charAt(i));
        }
        if(A.equals(B) && sA.size() < A.length()){
            return true;
        }
        List<Integer> l = new ArrayList<>();
        for(int i = 0; i < A.length(); i++){
            if(A.charAt(i) != B.charAt(i)){
                l.add(i);
            }
        }
        return l.size() == 2 && A.charAt(l.get(0)) == B.charAt(l.get(1)) && A.charAt(l.get(1)) == B.charAt(l.get(0));
    }
}