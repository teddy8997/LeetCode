class Solution {
public:
    int heightChecker(vector<int>& heights) {
        /*
            用另一個vector將正確位子都排出來再和原本的數列做比較看有幾個位子站錯
            time complexity: O(nlog(n))
            space complexity: O(n)
        */
        vector<int> correct(heights.begin(), heights.end());
        sort(correct.begin(), correct.end());
        int count = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != correct[i]){
                count++;
            }
        }
        return count;
    }
};