/*
		encoded[i] = arr[i] ^ arr[i+1]
	=>	encoded[i] ^ arr[i] = arr[i] ^ arr[i] ^ arr[i+1]
	=>	arr[i+1] = encoded[i] ^ arr[i]
	time complexity: O(n)
	space complexity: O(n)

*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> ans(n,first);
        for(int i = 0; i < n - 1; i++){
            ans[i+1] = encoded[i] ^ ans[i];
        }
        return ans;
    }
};