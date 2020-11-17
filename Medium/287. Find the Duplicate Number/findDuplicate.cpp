/*
	法一: 先將nums由小到大排序，再去兩個兩個比較有無相等
	time complexity: O(nlogn)
	space complexity: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
};
/*
	法二: 利用set來檢查重複數字
	time complexity: O(n)
	space complexity: O(n)

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       set<int> s;
        for(int n : nums){
            if(s.count(n)){
                return n;
            }
            s.insert(n);
        }
        return -1;
    }
};


