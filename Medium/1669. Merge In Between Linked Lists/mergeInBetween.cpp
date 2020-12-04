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
/*
    Time complexity: O(m+n)
    Space complexity: O(1)
*/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0);
        dummy.next = list1;
        ListNode* prev_a = &dummy; //紀錄list1到a的前一個點
        for(int i = 0; i < a; i++){
            prev_a = prev_a->next;
        }
        ListNode* node_B = prev_a->next; //紀錄去除a~b之後list1後半部第一個點
        for(int i = a; i <= b; i++){
            node_B = node_B->next;
        }
        ListNode *tail2 = list2; //找出list2的最後一個點
        while(tail2->next){
            tail2 = tail2->next;
        }
        prev_a->next = list2; //將list1到a的前一個點指向到list2的開頭
        tail2->next = node_B; //再將list2的最尾端的下一個點指向list1後半部第一個點
        return list1;
    }
};