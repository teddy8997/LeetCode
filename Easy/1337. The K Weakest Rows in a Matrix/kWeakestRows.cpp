class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if(mat.empty()){ //如果mat是空的就直接回空的vector
            return {};
        }
        int count = 0; //計算每一個row出現幾次1
        vector<pair<int, int>> tmp; //使用pair記錄每一row出現幾次1，並將此row的index跟1的出現次數存在一個vector中
        for(int i = 0; i < mat.size(); i++){
            count = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            tmp.push_back(make_pair(i, count));
        }
        //將tmp中的元素排序，如果有兩個row中的1出現次數相同，就將index較小的排在前面
        sort(tmp.begin(), tmp.end(), [](auto a, auto b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(tmp[i].first);
        }
        return ans;
    }
};