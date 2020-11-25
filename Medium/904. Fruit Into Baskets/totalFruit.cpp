/*
    這題題意就是從任意位置開始取水果，如果最多只能取兩種水果，最多可以連續取多少個水果
    那這題基本上就跟159. Longest Substring with At Most Two Distinct Characters一樣
    我們用一個hashMap紀錄每個水果出現次數，當HashMap中的映射超過兩個的時候我們就需要刪除一個映射，
    做法是sliding window的左邊界start水果的映射值減1，若是減到0的話就把那個映射刪除
    反之左邊界右移1位，當映射數量回到兩個的時候用當前的窗口大小來更新結果到res
    time complexity: O(n)
    space complexit: O(n)
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0;
        int start = 0;
        int n = tree.size();
        unordered_map<int, int> fruitCnt;
        for(int i = 0; i < n; i++){
            fruitCnt[tree[i]]++;
            while(fruitCnt.size() > 2){
                if(--fruitCnt[tree[start]] == 0){
                    fruitCnt.erase(tree[start]);
                }
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};