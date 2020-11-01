/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    先計算出listA跟listB的長度lengthA跟lengthB
    再計算兩個長度大小的差值，較長list的先走差值步
    兩個list再一步一步互相比較，如果沒有相交點代表會走到null
    
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        if(lengthA < lengthB){
            for(int i = 0; i < lengthB - lengthA; i++){
                headB = headB->next;
            }
        }else{
            for(int i = 0; i < lengthA - lengthB; i++){
                headA = headA->next;
            }
        }
        while(headA && headB && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB)? headA : NULL;
    }
private:
    int getLength(ListNode* n){
        int count = 0;
        while(n){
            n = n->next;
            count++;
        }
        return count;
    }
};