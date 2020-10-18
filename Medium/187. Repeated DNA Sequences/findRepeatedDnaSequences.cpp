class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //A: 0100 0001, C:0100 0011, G: 0100 0111, T: 0101 0100
        //可以發現這四個字符的後三位都不相同，所以我們可以利用這三個位來區分這四個字符
        //題目要求的是10個字符長度，每個字符用三個位來區分，10個字符需要30位。
        //那為了取出後30位需要使用一個mask值為0x7ffffff，此mask可以取出後27位
        //那我們只要將向左移3位後再和s[i]中的後三位做or就可以得到10個字符長度的串
        //再利用名稱為record的set容器來記錄有沒有出現過，有出現過就加入到ans中，沒出現過就加入record中
        unordered_set<string> ans;
        unordered_set<int> record;//利用一個set 來記錄字符串有沒有出現過

        int cur = 0;
        for(int i = 0; i < 9; i++){
            cur = cur << 3 | (s[i] & 7);
        }
        for(int i = 9; i < s.size(); i++){
            cur = ((cur & 0x7ffffff) << 3) | (s[i] & 7);
            if(record.count(cur)){
               ans.insert(s.substr(i - 9, 10));
            }else{
               record.insert(cur);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};