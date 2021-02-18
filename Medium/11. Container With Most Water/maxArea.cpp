/*
    使用two pointer，主要想法是使用兩個指針l指向最前面的index，r指向最後面的index
    兩個能裝的水量就是min(h[l], h[r]) * (r - l)
    然後如果h[l] < h[r]的話，我們保留較長的那一邊，將l往右移來找看看有沒有比現在的h[l]大
    反之亦然
    然後用一個變數area來一直更新最大的水量 
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int area = 0;
        while(l < r){
            int h = min(height[l], height[r]);
            area = max(area, h * (r - l));
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return area;
    }
};