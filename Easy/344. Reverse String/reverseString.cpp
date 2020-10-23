class Solution {
public:
    void reverseString(vector<char>& s) {
    	/*
    		非常基本的一題，用兩個指針i,j分別為0及s.size()-1
    		從前後兩邊一直交換直到i > j就完成
    	*/
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};