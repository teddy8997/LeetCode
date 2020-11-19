class Solution {
public:
    Solution(vector<int>& nums): v(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp = v;
        for(int i = 0; i < tmp.size(); i++){
            int t = i + rand() % (tmp.size() - i);
            //讓產生亂術後的座標跟當前座標做交換，最後會達到換了n次位子達到洗牌效果
            swap(tmp[i], tmp[t]);
        }
        return tmp;
    }
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */