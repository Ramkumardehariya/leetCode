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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* curr = NULL;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            curr = slow;
            slow = slow->next;
        }
        curr->next = slow->next;
        slow->next = NULL;
        return head;
    }
};