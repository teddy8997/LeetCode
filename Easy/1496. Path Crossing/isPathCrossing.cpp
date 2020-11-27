/*
    把經過的點都用SET記錄起來 檢查到達的點有沒有存在SET中了
    有的話返回true
    沒有的話返回false
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>> s;
        unordered_map<char, vector<int>> m{
            {'N', {0,1}},
            {'S', {0,-1}},
            {'E', {-1,0}},
            {'W', {1,0}}
        };
        vector<int> ans{0,0};
        s.insert(ans);
        for(char c : path){
            int x = ans[0] + m[c][0];
            int y = ans[1] + m[c][1];
            ans[0] = x;
            ans[1] = y;
            if(s.count(ans)){
                return true;
            }
            s.insert(ans);
        }
        return false;
    }
};