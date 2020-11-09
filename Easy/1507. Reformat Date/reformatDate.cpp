class Solution {
public:
    string reformatDate(string date) {
        /*
            這題也算簡單
            我們觀察輸入及輸出發現我們只要特別對日跟月做處理就行
            利用map把月的英文對應到月的數字
            然後日就把後面的英文去掉
            最後加上"-"串起來就是答案
            time complexity: O(1)
            space complexity: O(1)
        */
        unordered_map<string, string> m{{"Jan", "01"},
                                        {"Feb", "02"},
                                        {"Mar", "03"},
                                        {"Apr", "04"},
                                        {"May", "05"},
                                        {"Jun", "06"},
                                        {"Jul", "07"},
                                        {"Aug", "08"},
                                        {"Sep", "09"},
                                        {"Oct", "10"},
                                        {"Nov", "11"},
                                        {"Dec", "12"},
                                       };
        string ans = "";
        stringstream ss(date);
        string day = "";
        string month = "";
        string year = "";
        ss >> day >> month >> year;
        day = day.substr(0, day.size() - 2);
        if(day.size() == 1){
            day = "0" + day;
        }
        ans = year + "-" + m[month] + "-" + day;
        return ans;
    }
};