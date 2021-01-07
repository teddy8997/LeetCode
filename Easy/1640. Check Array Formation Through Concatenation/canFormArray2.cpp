class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, vector<int>> m;
        for(int i = 0; i < pieces.size(); i++){
            m[pieces[i][0]] = pieces[i];
        }
        int i = 0;
        while(i < arr.size()){
            int num = arr[i];
            auto it = m.find(num);
            if(it == m.end()){
                return false;
            }
            auto p1 = m[num];
            for(int j = 1; j < p1.size(); j++){
                if(p1[j] != arr[i+j]){
                    return false;
                }
            }
            i += p1.size();
        }
        return true;
    }
};