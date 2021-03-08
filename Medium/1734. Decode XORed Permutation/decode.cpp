/*
    Input: encoded = [6,5,4,6]
    Output: [2,4,1,5,3]
    把encoded全部XOR起來得到的是 nums[0] ^ nums[n-1]
    題目又說n是奇數所以我們可以想到，
    encode[1] = nums[1] ^ nums[2]
    encode[3] = nums[3] ^ nums[4]
    我們又知道nums數組全部XOR的值是xorAll =  1 ^ 2 ^ ... ^ (n)
    所以我們可以用這些條件求出nums[0]
    也就是xorAll ^ encoded[1] ^ encoded[3]
    接下來就一一求出後面的數字

*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int xorAll = 0;
        int n = encoded.size()+1;
        for(int i = 1; i <= n; i++){
            xorAll ^= i;
        }
        int noheadSum = 0;
        for(int i = 1; i < encoded.size(); i+=2){
            noheadSum ^= encoded[i]; 
        }
        int head = xorAll ^ noheadSum;
        vector<int> ans(n);
        ans[0] = head;
        for(int i = 1; i < n; i++){
            ans[i] = encoded[i - 1] ^ ans[i-1];
        }
        return ans;
    }
};