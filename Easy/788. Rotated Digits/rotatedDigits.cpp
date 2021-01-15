/*
	對於每個數把轉成字串後再每一位每一位遍歷。
	題目規則沒有講到3 4 7 所以這三個數字不能被翻轉，只要遇到這三個數就是false
	0 1 8 這三個數翻轉後還是其本身，由於好數的定義是要翻轉一個不同的數字，所以如果都是由這三個數構成的話翻轉後不會產生不同的數，
	不符合題意，所以需要 2 5 6 9至少出現一個，所以使用一個flag來記錄有沒有出現過這些數字。最後只須回傳flag即可
*/
class Solution {
public:
    int rotatedDigits(int N) {
        int ans = 0;
        for(int i = 1; i <= N; i++){
            if(check(i)){
                ans++;
            }
        }
        return ans;
    }
private:
    bool check(int k){
        string s = to_string(k);
        bool flag = false;
        for(char c : s){
            if(c == '3' || c == '4' || c == '7'){
                return false;
            }
            if(c == '2' || c == '5' || c == '6' || c == '9'){
                flag = true;
            }
        }
        return flag;
    }
};