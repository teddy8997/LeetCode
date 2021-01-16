/*
    把text變成字串組後再一個一個檢查
    time complexity: O(n * l) n: 單字數 , l: 單字長度
    space complexity: O(n)
*/
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> tmpString;
        stringstream ss(text);
        string tmp = "";
        while(ss >> tmp){
            tmpString.push_back(tmp);
        }
        vector<string> ans;
        for(int i = 0; i < tmpString.size() - 2; i++){
            if(tmpString[i] == first && tmpString[i + 1] == second){
                ans.push_back(tmpString[i+2]);
            }
        }
        return ans;
    }
};