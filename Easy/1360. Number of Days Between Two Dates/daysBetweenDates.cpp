/*
    Time complexity: O(1)
    Space complexity: O(1)
*/
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return abs(Days(date1) - Days(date2));
    }
private:
    vector<int> m;
    bool isLeap(int year){
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
    int Days(string date){
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int days = stoi(date.substr(8,2));
        for(int i = 1970; i < year; i++){
            days += 365 + isLeap(i);
        }
        for(int i = 1; i < month; i++){
            days += m[i - 1];
        }
        days += month > 2 && isLeap(year);
        return days;
    }
};