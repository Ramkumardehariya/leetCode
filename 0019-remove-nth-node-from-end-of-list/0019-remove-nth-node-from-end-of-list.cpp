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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp = head;
        // ListNode* prev = NULL;

        // int count = 0;
        // while(temp != NULL){
        //     count++;
        //     temp = temp->next;
        // }
        // temp = head;
        // if(count == n){
        //     return temp->next;
        // }
        // int i = 0;
        // while(i<count-n){
        //     i++;
        //     prev = temp;
        //     temp = temp->next;
        // }
        // prev->next = temp->next;
        // temp->next = NULL;
        // delete(temp);
        // return head;

        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;

        for(int i = 1; i<=n; i++){
            fast = fast->next;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        
        return start->next;
    }
};