class Solution {
public:
    bool canJump(vector<int>& nums) {
        //利用greedy法，我們只需要注意最遠能夠到達的位子
        //所以利用一個變數reach表示最遠能夠到達的位子
        //再來遍歷數組中的每一個數字如果目前的index > reach 或是reach已經抵達最後一個位子就跳出迴圈
        //否則就更新reach = max(reach, nums[i]+i),nums[i]+i表示當前位置能到達的最大位子
        int reach = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > reach || reach >= n-1){
                break;
            }
            reach = max(reach, nums[i]+i);
        }
        return reach >= n-1;
    }
};