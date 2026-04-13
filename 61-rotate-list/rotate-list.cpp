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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head-> next || k == 0 ) return head;

        ListNode*  temp = head;
        int length = 1;

        while(temp -> next != NULL){
          temp = temp -> next;
          length++;
        }
         
         temp -> next = head;

         k = k % length;

        int stepsTonewTail = length - k;
        
        ListNode* newTail = head;
        for( int i = 1; i< stepsTonewTail; i++){
          newTail = newTail -> next;
        }

        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;

        return newHead;
    }
};