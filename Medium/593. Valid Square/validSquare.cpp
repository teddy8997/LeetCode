/*
	先想想怎麼判斷4個點能不能構成正方形，從幾何學上我們來看四個邊等長而且兩個對角線會等長
	我們利用set來記錄每兩個點之間的距離，若滿足4個邊等長且對角線會等長 最後set中去掉重複的數字會剩下2個
	但是這邊要注意要多判斷一個點有沒有重疊也就是距離為0的情況
	Time complexity: O(1)
	Space complexity: O(1)
*/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s{dirSqt(p1, p2), dirSqt(p1, p3), dirSqt(p1, p4), 
                   dirSqt(p2, p3), dirSqt(p2, p4), dirSqt(p3, p4)};
        return !s.count(0) && s.size() == 2;
    }
private:
    int dirSqt(vector<int>& p1, vector<int>& p2){
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};