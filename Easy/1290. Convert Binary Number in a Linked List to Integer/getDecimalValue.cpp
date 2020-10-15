class Solution {
public:
    int getDecimalValue(ListNode* head) {
        /*方法1
        while(true){
            res += to_string(head->val);
            head = head->next;
            if(!head){
                break;
            }
        }
        
        return stoi(res,0,2);
        */
        //方法二
        int res = 0;
        while(head){
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};