// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        bool firstReverse = false;
        ListNode* headR = new ListNode(0, head);
        ListNode* current = head, *aux1, *aux2, *aux3, *aux4 = headR;
        while(true){
            aux1 = current;
            if(!current) return headR->next;
            for(int i = 0; i < k-1; i++){
                if(!current->next) return headR->next;
                current = current->next;
            }
            current = aux1;
            aux2 = current->next;
            aux3 = aux2->next;
            for(int i = 0; i < k-1; i++){
                aux2->next = current;
                current = aux2;
                aux2 = aux3;
                if(aux3) aux3 = aux3->next;
            }
            aux4->next = current;
            aux4 = aux1;
            aux1->next = aux2;
            current = aux2;
        }
    }
};
