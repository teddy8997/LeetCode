class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //題目禁止使用除法所以我們要另外想辦法
        //我們只要知道當前位置的數字前面數字所有的乘積和出現當前位置後面的數字的所有乘積
        //這樣把兩個相乘就是我們要的結果
        int n = nums.size();
        vector<int> l(n,1);
        vector<int> r(n,1);
        vector<int> ans(n);
        for(int i = 0; i < n-1; i++){
            l[i+1] = l[i] * nums[i];  //紀錄每個位置的前面乘積
        }
        for(int i = n-1; i > 0; i--){
            r[i-1] = r[i] * nums[i]; //紀錄每個位置的後面乘積
        }
        for(int i = 0; i < n; i++){ //將兩個陣列的元素相乘就是所求
            ans[i] = l[i] * r[i];
        }
        return ans;
    }
};