class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> m;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int tmp = nums[i] * nums[j];
                if(m.count(tmp)){
                    count += 8 * m[tmp];
                }
                m[tmp]++;
            }
        }
        return count;
    }
};