/* brute force TLE*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0;
       for(int i = 0; i < dominoes.size()-1; i++){
           for(int j = i+1; j < dominoes.size(); j++){
               if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1])
                  || (dominoes[i][1] == dominoes[j][0] && dominoes[i][0] == dominoes[j][1])){
                   cnt++;
               }
           }
       }
        return cnt;
        }
};
/*
  Time complexity: O(n)
  Space complexity: O(100)
*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> m(100);
        int ans = 0;
        for(auto n : dominoes){
            int k1 = n[0] * 10 + n[1];
            int k2 = n[1] * 10 + n[0];
            ans += m[k1];
            if(k1 != k2){
                ans += m[k2];
            }
            m[k1]++;
        }
        return ans;
    }
};