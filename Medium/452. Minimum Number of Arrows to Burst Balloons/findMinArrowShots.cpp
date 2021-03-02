/*
    使用貪心法
    這題要注意的是區間起點和終點重疊的話氣球也會爆炸

    如果最多有n個不重疊的區間那麼最少就需要n個弓箭
    time complexity: O(nlogn)
    space complexity: O(1)
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0){
            return 0;
        }
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2){
            return p1[1] < p2[1];
        });
        int end = points[0][1];
        int count = 1;
        for(vector<int> p : points){
            int start = p[0];
            if(start > end){
                count++;
                end = p[1];
            }
        }
        return count;
    }
};