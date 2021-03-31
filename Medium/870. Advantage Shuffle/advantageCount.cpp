
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int leftIdx = 0;
        int rightIdx = A.size() - 1;
        priority_queue<pair<int,int>> Belement;
        sort(A.begin(), A.end());
        vector<int> ans(A.size());
        for(int i = 0; i < B.size(); i++){
            Belement.push({B[i], i});
        }
        while(!Belement.empty()){
            int maxElementInB = Belement.top().first;
            int idx = Belement.top().second;
            Belement.pop();
            if(A[rightIdx] > maxElementInB){
                ans[idx] = A[rightIdx];
                rightIdx--;
            }else{
                ans[idx] = A[leftIdx];
                leftIdx++;
            }
        }
        return ans;
    }
};