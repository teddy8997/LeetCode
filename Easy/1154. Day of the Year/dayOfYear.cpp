/*
    time complexity: O(1)
    space cpmplexity: O(1)
*/
class Solution {
public:
    int dayOfYear(string date) {
        vector<int> m{31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        int ans = 0;
        for(int i = 0; i < month-1; i++){
            ans += m[i];
        }
        ans += day;
        if(leap == 1 && month > 2){
            ans++;
        }
        return ans;
    }
};