class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        /*
            Time complexity: O(n*log(k))
            Space complexity: O(1)
        */
        int l = 1;
        int r = 1e6;
        while(l < r){
            int m = l + (r - l) / 2;
            if(sum(m, nums) <= threshold){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
private:
    int sum(int m, vector<int>& nums){
        int s = 0;
        for(int n : nums){
            if(n % m != 0){
                s += (n / m) + 1;
            }else{
                s += (n / m);
            }
        }
        return s;
    }
};