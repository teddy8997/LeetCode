/*
	這題就是要考你給定的點是否為三點共線
	我們可以使用斜率的方式來檢查是否有共線
	三點共線的條件為任兩點斜率相同:
		dy1 / dx1 == dy2 / dx2
	 	dy / dx = (y2 - y1) / (x2 - x1)
	 為了避免除以0這種情況我們使用: dx2 * dy1 != dy2 * dx1 來判斷沒有共線
	  
	time complexity: O(1)
	space complexity: O(1)
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int dx1, dx2, dy1, dy2;
        dx1 = points[0][0] - points[1][0];
        dy1 = points[0][1] - points[1][1];
        
        dx2 = points[1][0] - points[2][0];
        dy2 = points[1][1] - points[2][1];
        
        return dx2 * dy1 != dx1 * dy2; 
    }
};