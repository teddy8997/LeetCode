/*
    題目說我們可以在數列中選一數加一個負號，重複K次，求這個數組中全部的數的和會最大

    因為題目沒有檢查最後答案 原本數組會變成怎麼樣的數組
    所以我們可以先進行排序，從小排到大
    翻轉最小的負數成正數，翻轉玩一個負數後K--
    如果翻轉完負數後K還有剩，檢查K是奇數還是偶數，偶數的話 相當於正負都用在同一個數所以抵銷可以不用考慮，
    奇數的話就選擇最小的數來加負號，所以將總和扣掉最小的數 * 2 (因為正負差了兩倍)就是答案
    
    time complexity: O(nlogn)
    space complexity: O(1)
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for(int &a : A){
            if(K == 0){
                break;
            }
            if(a < 0){
                a = -a;
                K--;
            }
        }
        return accumulate(A.begin(), A.end(), 0) - (K % 2 ? *min_element(A.begin(), A.end()) * 2 : 0) ;
    }
};