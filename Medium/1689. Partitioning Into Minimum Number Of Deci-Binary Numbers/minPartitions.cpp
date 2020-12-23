/*
	題目給定一個數字字串表示十進位的數字，要我們求出用最左邊一位不為0的二進位的數相加變成這個十進位的數字所需的最小數目
	我們觀察一下這題就等於是求出這串數字的最大值就是答案
	
	time complexity: O(n)
	space complexity: O(1)
*/
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n){
            ans = max(ans, c - '0');
        }
        return ans;
    }
};