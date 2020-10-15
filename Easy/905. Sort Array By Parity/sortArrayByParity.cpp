class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans(A.size(),0);
        int j = 0;
        int k = A.size()-1;
        //使用 j 指針從index:0 紀錄偶數位置,k指針從最後面 index: A.size()-1 紀錄奇數位置
        //偶數存到位置j後j++
        //奇數存到位置k後k--
        for(int a : A){
            if(a % 2 == 0){ 
                ans[j] = a;
                j++;
            }else{
                ans[k] = a;
                k--;
            }
        }
        return ans;
    }
};