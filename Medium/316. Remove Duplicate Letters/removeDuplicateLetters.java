class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> T = new Stack<>();
        StringBuilder sb = new StringBuilder();
        //紀錄字母出現次數
        int [] cnt = new int [26];
        //紀錄字母有沒有使用過
        boolean [] used = new boolean[26];
        for(char c : s.toCharArray()){
            cnt[c - 'a']++;
        }

        for(char c : s.toCharArray()){
            cnt[c - 'a']--;
            if(used[c - 'a'] == true){ //若此字母已經使用過就讓迴圈繼續
                continue;
            }
            //若是儲存的答案STACK中不是空的 且 STACK中最後一個字母順序大於接下來要加入的字母c 且 STACK中最後一個字母在接下來還會出現
            //就將 STACK中最後一個字母標示為尚未走過 然後POP出STACK
            while(!T.isEmpty() && T.peek() > c && cnt[T.peek() - 'a'] > 0){
                used[T.peek() - 'a'] = false;
                T.pop();
            }

            T.push(c);
            used[c - 'a'] = true;
        }
        
        for(char c : T){
            sb.append(c);
        }
        return sb.toString();
        
    }
}