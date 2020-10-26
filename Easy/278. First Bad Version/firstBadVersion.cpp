// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
            這題可以用二分搜尋法來找到第一個出現的壞版本
            如果說在m時為壞版本代表他的右邊全都是壞的所以我們要往左邊找
            如果說在m時為好版本代表他的左邊全都是好的所以我們要往右邊找
        */
        int l = 1;
        int r = n;
        while(l < r){
            int m = l + (r - l) / 2;
            if(isBadVersion(m)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};