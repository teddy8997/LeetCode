class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> m;
        //將strs字串組中的每個字串裡的每個字母由小到大排序後
        //當作key並將當前的index存到map中
        //再將map中的元素遍歷取出，取出map中的每一組value，
        //將裡面已經歸類的好index來從strs取原本的字串並存回ans
        for(int i = 0; i < strs.size(); i++){
            string c = strs[i];
            sort(c.begin(), c.end());
            m[c].push_back(i);
        }
        for(auto KV : m){
            ans.push_back({});
            for(auto t : KV.second){
                ans.back().push_back(strs[t]);
            }
        }
        return ans;
    }
};