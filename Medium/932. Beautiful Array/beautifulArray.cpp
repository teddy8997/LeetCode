class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans{1};
        while(ans.size() < N){
            vector<int> t;
            for(int num : ans){
                if(num * 2 - 1 <= N){
                    t.push_back(num * 2 - 1);
                }    
            }
            for(int num : ans){
                if(num * 2 <= N){
                    t.push_back(num * 2);
                }
            }
            ans = t;   
        }
        return ans;
    }
};