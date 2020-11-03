class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        /*
            法一:暴力法
            time complexity: O(n^2)
            space complexity: O(1)
        */
        /*
        for(int i = 0; i < arr.size()-1; i++){
            for(int j = i+1; j < arr.size(); j++){
                if(arr[i] == 2 * arr[j] || 2* arr[i] == arr[j]){
                    return true;
                }
            }
        }
        return false;
        */
        
        /*
            法二: 利用hashmap
            time complexity: O(n)
            space complexity: O(n)
        */
        unordered_map <int, int> m; 
        for(int i = 0; i < arr.size(); i++){
            if(m.count(arr[i] * 2) || (arr[i] % 2 == 0 && m.count(arr[i] / 2))){
                return true;
            }
            m[arr[i]] = i;
        }
        return false;
    }
};