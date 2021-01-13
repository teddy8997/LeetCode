/*
    依據題目box[i][j]中 i 代表此類型的箱子有幾個，j 代表此類型的箱子裡有幾樣東西。
    我們先把box根據j由大到小排序，這樣表示東西多的在前面。
    然後我們對這個數組遍歷，卡車還裝得下時也就是truckSize > 0時，嘗試將當前類型的箱子一一塞入直到當前的箱子搬完或是卡車裝不下為止。
    time complexity: O(nlogn)
    space complexity: O(1)
*/
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        int sum = 0;
        for(int i = 0; i < boxTypes.size(); i++){
            while(truckSize > 0 && boxTypes[i][0] > 0){
                sum += boxTypes[i][1];
                truckSize--;
                boxTypes[i][0]--;
            }
        }
        return sum;
    }
};