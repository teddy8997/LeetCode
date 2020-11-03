class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
    	/*
			法一:最簡單的想法就是把A裡面的數字都更新成平方數後
			從小到大排序
			time complexity: O(nlog(n))
			sapce complexity: O(1)
    	*/
    	/*
        for(int i = 0; i < A.size(); i++){
            A[i] = A[i] * A[i];
        }
        sort(A.begin(), A.end());
        return A;
        */
        /*
        	法二:因為原數列已經由小到大排好且有可能包含負數
        	我們的想法是平方後最大值一定出現在最左或是最右邊所以我們利用兩個變數儲存最左跟最右遍歷到的index
        	然後要回傳的數列從最右邊開始填，若原數列左邊取絕對值比右邊的數大代表左邊平方會比右邊平方大
        	所以把左邊的平方值填入ans中
        	然後left index + 1
        	其他的就以此類推
        	time complexity: O(n)
        	Sapce complexity: O(n)
        */
        vector<int> ans(A.size(), 0);
        int left = 0;
        int right = A.size() - 1;
        for(int i = ans.size()-1; i >= 0; i--){
            if(abs(A[left]) > abs(A[right])){
                ans[i] = A[left] * A[left];
                left++;
            }else{
                ans[i] = A[right] * A[right];
                right--;
            }
        }
        return ans;
};