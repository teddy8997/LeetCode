/*
    
    Time complexity: O(1)
    Space complexity: O(1)
*/
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> dayNames{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> days{31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sum = 0;
        for(int i = 1970; i < year; i++){
            sum += 365 + isLeap(i);
        }
        for(int i = 1; i < month; i++){
            sum += days[i - 1];
        }
        sum += day;
        return dayNames[(sum + 3) % 7];
    }
private:
    bool isLeap(int year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); 
    }
};