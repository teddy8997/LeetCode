/*
    想法就是把2進位轉成10進位後%5 餘數若是0 則是true
    反之則是false
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {  
        vector<bool> ans;
        int prefix = 0;
        for(int n : A){
            prefix = (prefix * 2 + n) % 5;
            if(prefix == 0){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};