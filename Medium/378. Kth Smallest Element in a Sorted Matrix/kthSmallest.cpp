/*
    暴力法: 將每個元素都加到vecotor中
    time complexity: O(n^2)
    space complexity: O(n)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> tmp;
        for(auto i : matrix){
            for(auto j : i){
                tmp.push_back(j);
            }
        }
        sort(tmp.begin(), tmp.end());
        return tmp[k-1];
    }
};