clasclass Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map <char, int> lastPosition;
        for(int i = 0; i < S.size(); i++){ //紀錄每個字母的最後一個位子
            lastPosition[S[i]] = i;
        }
        int start = 0;
        int last = 0;
        //一個一個遍歷並且比較目前遍歷到的字母出現的最後位子取較大的值，當你i遍歷到目前加入的字母中的最後位子代表後面都不會出現前面的字母了所以可以分割
        for(int i = 0; i < S.size(); i++){ 
            last = max(last, lastPosition[S[i]]);
            if(i == last){
                res.push_back(i - start + 1);
                start = i+1;
            }
        }
        return res;
    }
};