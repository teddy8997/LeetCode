class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> s = new HashSet<>();
        for(String e : emails){
            String name = "";
            for(char c : e.toCharArray()){
                if(c == '.'){
                    continue;
                }
                if(c == '@' || c == '+'){
                    break;
                }
                name += c;
            }
            name += e.substring(e.indexOf('@'),e.length());
            s.add(name);
        }
         return s.size();
    }
}