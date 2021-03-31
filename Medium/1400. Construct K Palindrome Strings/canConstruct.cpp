class Solution {
public:
    bool canConstruct(string s, int k) {
        int sLength = s.size();
        if(sLength < k){
            return false;
        }
        if(sLength == k){
            return true;
        }
        vector<int> frequency(26, 0);
        for(char c : s){
            frequency[c - 'a']++;
        }
        int countOddFrequency = 0;
        for(int i = 0; i < 26; i++){
            if(frequency[i] % 2 == 1){
                countOddFrequency++;
            }
        }
        return countOddFrequency <= k;
    }
};