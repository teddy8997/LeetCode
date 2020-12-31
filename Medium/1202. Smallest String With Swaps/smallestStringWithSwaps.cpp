/*
    參考https://zxi.mytechroad.com/blog/graph/leetcode-1202-smallest-string-with-swaps/
    一個一個找出每個連通圖，再將它們排序
    
    time complexity: O(nlogn + k *(V + E))
    space complexity: O(n)
*/
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>>g(s.size());
        unordered_set<int> seen;
        vector<int> index;
        string tmp;
        for(vector<int> e : pairs){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < s.size(); i++){
            if(seen.count(i)){
                continue;
            }
            index.clear();
            tmp.clear();
            dfs(i, g, seen, index, tmp, s);
            sort(tmp.begin(), tmp.end());
            sort(index.begin(), index.end());
            for(int k = 0; k < index.size(); k++){
                s[index[k]] = tmp[k];
            }
        }
        return s;
    }
private:
    void dfs(int cur, vector<vector<int>> &g, unordered_set<int> &seen, vector<int> &index, string &tmp, string &s){
        if(seen.count(cur)){
            return;
        }
        seen.insert(cur);
        index.push_back(cur);
        tmp += s[cur];
        for(int nxt : g[cur]){
            dfs(nxt, g, seen, index, tmp, s);
        }
    }
};