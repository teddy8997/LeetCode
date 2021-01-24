/*
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> ans(n+1);
        ans[0] = 0;
        int i = 1;
        for(int num : gain){
            ans[i] = ans[i - 1] + num;
            i++;
        }
        return *max_element(ans.begin(), ans.end());
    }
};