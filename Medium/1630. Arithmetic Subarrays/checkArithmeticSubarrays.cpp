/*
    寫一個function來判斷是否為Arithmatic 數組，然後將給定範圍的數從小排到大去判斷兩數之間的差是否皆相同
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i = 0; i < m; i++){
            bool AirthResult = isArithmetic(nums, l[i], r[i]);
            ans.push_back(AirthResult);
        }
        return ans;
    }
private:
    bool isArithmetic(vector<int>& nums, int s, int e){
        vector<int> tmp(nums.begin() + s, nums.begin() + e + 1);
        sort(tmp.begin(), tmp.end());
        int d = tmp[1] - tmp[0];
        for(int i = 2; i < tmp.size(); i++){
            if(tmp[i] - tmp[i-1] != d){
                return false;
            }
        }
        return true;
    }
};