/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
            因為題目說不能修改LIST我們又需要從後面開始遍歷
            所以我們可以利用STACK來達成先存取後面數的效果
            我們先建立一個值為0的ans節點然後開始循環把不為空的STACK加入SUM中
            把ans的節點附值成sum % 10然後建立一個新的進位節點head附值sum / 10
            那如果沒進為這個節點就是0,然後將head指向ans，ans移到head
            因此退出迴圈後就要檢查res是不是0
            
        */
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *ans = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            ans->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = ans;
            ans = head;
            sum = sum / 10;
        }
        return ans->val == 0? ans->next : ans;
    }
};