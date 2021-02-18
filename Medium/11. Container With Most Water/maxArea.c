int maxArea(int* height, int heightSize){
        int l = 0;
        int r = heightSize - 1;
        int area = 0;
        while(l < r){
            int h = height[l] < height[r]? height[l] : height[r];
            area = area > h * (r - l)? area : h * (r - l);
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return area;
}