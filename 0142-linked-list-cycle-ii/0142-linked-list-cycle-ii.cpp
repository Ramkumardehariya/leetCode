/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
    
        ListNode *prev = head;
        ListNode *curr = head;

        while(curr != NULL || curr->next != NULL){
            prev = prev->next;
            curr = curr->next;
            if(curr->next != NULL){
                curr = curr->next;
            }

            if(prev == curr){
                break;
            }
        }
        if(curr == NULL || curr->next == NULL){
            return NULL;
        }

        ListNode* temp = head;

        while(temp != curr){
            temp = temp->next;
            curr = curr->next;
        }

        return curr;
    }
};