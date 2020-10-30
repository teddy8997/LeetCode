class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        /*
            法一: use another vector to store the number with duplicate zeros.
            time complexity : O(n)
            space complexity: O(n)
        */
        /*
        vector<int> tmp;
        for(int n : arr){
            if(n == 0){
                tmp.push_back(0);
            }
            tmp.push_back(n);
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = tmp[i];
        }
        */
        /*
            法二: two pointers
            使用zeroCount變數紀錄0的個數出現幾次，j為原本陣列長度加上重複0的長度，j = arr.size() + n
            由arr的最後往前面遍歷，讓i先走zeroCount步然後當j < arr.size()時就把index i的數填到index j
            要注意如果arr[i]是0的話j必須再減一填一次0
        */
        int zeroCount = 0;
        int size = arr.size();
        for(int n : arr){
            if(n == 0){
                zeroCount++;
            }
        }
        int j = zeroCount + size;
        for(int i = size - 1; i >= 0; i--){
            if(--j < size){
                arr[j] = arr[i];
            }
            if(arr[i] == 0 && --j < size){
                arr[j] = 0;
            }
        }
    }
};