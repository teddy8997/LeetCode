class Solution {
    public String maximumTime(String time) {
        char [] timeC = time.toCharArray();
        char [] ans = time.toCharArray();
         if(timeC[0] == '?'){
            if(timeC[1] == '?' || timeC[1] <= '3'){
                ans[0] = '2'; // ?? , ?3
            }else{
                ans[0] = '1'; // ?4, ?5, ?6.....
            }
        }
        if(timeC[1] == '?'){
            if(timeC[0] == '0' || timeC[0] == '1'){
                ans[1] = '9'; // 0?, 1?
            }else if(timeC[0] == '2' || timeC[0] == '?'){
                ans[1] = '3'; // 2?, ??
            }
        }
        if(timeC[3] == '?'){
            ans[3] = '5';
        }
        if(timeC[4] == '?'){
            ans[4] = '9';
        }
        return new String(ans);
    }
}