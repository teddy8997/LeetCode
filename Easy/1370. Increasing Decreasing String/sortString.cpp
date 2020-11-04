class Solution {
public:
    string sortString(string s) {
        /*
            time complexity:O(n)
            space complexity:O(n)
        */
        vector<int> count(26,0);
        int n = s.size();
        for(char c : s){
            count[c - 'a']++;
        }
        string ans = "";
        while(n > 0){
            //從'a'到'z'開始找找到不能找
            for(int i = 0; i < 26; i++){
                if(count[i] > 0){
                    ans += ('a' + i);
                    count[i]--;
                    n--;
                }
            }
            //從'z'到'a'開始找找到不能找
            for(int i = 25; i >= 0; i--){
                if(count[i] > 0){
                    ans += ('a' + i);
                    count[i]--;
                    n--;
                }
            }
        }
        return ans;
    }
};