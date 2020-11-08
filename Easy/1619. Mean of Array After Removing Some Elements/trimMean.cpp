class Solution {
public:
    double trimMean(vector<int>& arr) {
    	/*
			簡單的一道題目
			先小到大排序之後，算出前後要踢掉幾個數字offset
			然後使用累加函數從begin() + offset累加到arr.end() - offset
			最後再除以原本的數字個數 - 前後被剔除的個數
			Time complexity: O(nlogn)
			Space complexity: O(1)
    	*/
        sort(arr.begin(), arr.end());
        int offset = arr.size() / 20;
        int sum = accumulate(arr.begin() + offset, arr.end() - offset, 0);
        return (double)(sum) / (arr.size() - 2 * offset);
    }
};