class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        int sumB = 0;
        //分別計算A,B的糖果總數，既然要兩個人交換使兩個人的糖果總數相等
        //我們就去計算A,B糖果總數的差值 / 2, 表示每個人負擔差值的一半
        //所以我們只要去找B的個別糖果數加上這個差值會出現在A中的數就行
        for(int num : A){
            sumA += num;
        }
        for(int num : B){
            sumB += num;
        }
        int diff = (sumA - sumB) / 2;
        set<int> sA(A.begin(), A.end());
        for(int num : B){
            if(sA.count(num + diff)){
                return {num + diff, num};
            }
        }
        return {};
    }
};