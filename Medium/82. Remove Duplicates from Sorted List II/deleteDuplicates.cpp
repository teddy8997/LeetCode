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
    ListNode* deleteDuplicates(ListNode* head) {
        /*
            time complexity:O(n)
            space complexoty:O(1)
        */
        if(!head){
           return nullptr; 
        }
        ListNode dummy(0);
        ListNode *p = &dummy;
        while(head){
            int c = 0;
            //當下一個節點不是空而且現在的節點值和下一個節點值相同的話c++
            while(head->next && head->val == head->next->val){
                head = head->next;
                c++;
            }
            //c = 0代表當前節點的值沒有和下一個重複所以將p指向目前這個head,p再向下移
            if(c == 0){
                p->next = head;
                p = p->next;
            }else{//如果c != 0代表有重複所以先把p指向null
                p->next = nullptr;    
            }
            //head移往下一個節點
            head = head->next;
        }
        return dummy.next;
    }
};