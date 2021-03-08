/*
    照題意模擬就行
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int i = 0;
        int dis = INT_MAX;
        int idx = -1;
        for(vector<int> p : points){
            if(p[0] == x || p[1] == y){
                if(dis > abs(x - p[0]) + abs(y - p[1])){
                    dis = abs(x - p[0]) + abs(y - p[1]);
                    idx = i;
                }
            }
            i++;
        }
        return idx;
    }
};