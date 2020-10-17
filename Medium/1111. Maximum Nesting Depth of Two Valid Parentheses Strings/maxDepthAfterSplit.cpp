class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int count = 0;//紀錄未補全的左括號數目
        int pos = 0;//紀錄當前遍歷的位置
        vector<int> ans(seq.size()); //返回的答案vector

        for(char c : seq){
            if(c == '('){ //遇到左括號的話要去判斷未補全的左括號數要分配給A還是B
                count++;//未補全的左括號數+1
                //如果未補全的左括號數目是奇數，那麼目前新的左括號分配給A，答案結果填入0
                //如果未補全的左括號數目是偶數，那麼目前新的左括號分配給B，答案結果填入1
                ans[pos] = 1 - count % 2;
            }else{//遇到右括號則和最後分配的左括號一樣最後分配給A就填入0最後分配給B就填入1
                ans[pos] = 1 - count % 2;
                count--;//分配完後未補全的左括號-1
            }
            pos++;//往下一個括號遍歷
        }
        return ans;
    }
};