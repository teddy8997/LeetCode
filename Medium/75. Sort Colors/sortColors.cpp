/*
    法一: 因為只會出現0 1 2所以我們利用一個vector來記錄每一個出現次數
    再將記錄回填nums
    time complexity: O(n^2)
    space complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> co(3,0);
        for(int n : nums){
            co[n]++;
        }
        int cur = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < co[i]; j++){
                nums[cur] = i;
                cur++;
            }
        }
    }
};
/*
    法二
    利用兩個指針
    紅指針從0開始
    藍指針從最尾巴開始
    如果遇到0當前位子跟red位子交換後 red向後移一位
    如果遇到2當前位子跟blue位子交換後 blue向前移一位
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;
        for(int i = 0; i <= blue; i++){
           if(nums[i] == 0){
               swap(nums[i], nums[red++]);
           }else if(nums[i] == 2){
               swap(nums[i--], nums[blue--]);
           }
        }
    }
};