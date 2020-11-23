/*
    這題馬上想到的是要幫數組逕行排序可是該怎麼排呢?
    對於兩個數字a,b來說轉為字串, 如果ab > ba 則a排在前面
    例如: a = 9, b = 34, 934 > 349 所以9排在前面
    例如: a = 30, b = 3, 303 < 330 所以3排在30的前面
    依照這種規則我們可以把每個數字轉化成字串再相連接起來來排序
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for(int i = 0; i < nums.size(); i++){
            ans += to_string(nums[i]);
        }
        return ans[0] == '0'? "0" : ans; //記得最後要檢查是不是[0,0] => 00的這種情況，如果是要輸出0
    }
};