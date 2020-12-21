/*
    這題題目是給定兩個矩形的左下點座標及右上點座標，求出兩個矩形有沒有重疊
    那我們只要畫出假設右上重疊的圖
    並且去算出重疊的矩形的左下及右上的點座標,再去判斷這個左下及右上的座標有無符合構成矩形的條件

    重疊的   x => max(x1,x3) < x < min(x2, x4)
            y => max(y1, y3) < y < min(y2, y4)
    time complexity: O(1)
    space complexity: O(4)
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = max(rec1[0], rec2[0]);
        int y1 = max(rec1[1], rec2[1]);
        int x2 = min(rec1[2], rec2[2]);
        int y2 = min(rec1[3], rec2[3]);
        if(x1 < x2 && y1 < y2){
            return true;
        }else{
            return false;
        }
    }
};