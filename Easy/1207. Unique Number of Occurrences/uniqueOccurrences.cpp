class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> count;
        //計算每個數字出現的次數
        for(int num : arr){
            count[num]++;
        }
        set<int> s;
        //並把出現次數利用set來檢查有沒有重複
        for(auto it = count.begin(); it != count.end(); it++){
            s.insert(it->second);
        }
        //如果有重複set裡面元素各數會和原本map中的元素個數不一樣
        return s.size() == count.size();
    }
};