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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        ListNode* odd = new ListNode(0);
        ListNode* odd_tail = odd;
        int count = 1;

        ListNode* even = new ListNode(0);
        ListNode* even_tail = even;

        ListNode* curr = head;

        while(curr != NULL){
            if(count % 2 == 1){
                odd_tail->next = curr;
                odd_tail = odd_tail->next;
            }
            else{
                even_tail->next = curr;
                even_tail = even_tail->next;
            }
            count++;
            curr = curr->next;
        }

        odd_tail->next = even->next;
        even_tail->next = NULL;

        return odd->next;

    }
};