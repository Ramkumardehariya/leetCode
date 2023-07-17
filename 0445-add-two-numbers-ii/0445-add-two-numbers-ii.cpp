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
    ListNode* reverse(ListNode* head){
        if(head->next == NULL){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;

        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        head = prev;

        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head1 = reverse(l1);
        ListNode* head2 = reverse(l2);
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        int carry = 0;
        while(head1 != NULL && head2 != NULL){
            int sum = head1->val + head2->val + carry;
            
            int node = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node);
            curr->next = temp;
            curr = curr->next;
            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1 != NULL){
            int sum = head1->val + carry;
            
            int node = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node);
            curr->next = temp;
            curr = curr->next;
            head1 = head1->next;
        }

        while(head2 != NULL){
            int sum = head2->val + carry;
            
            int node = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node);
            curr->next = temp;
            curr = curr->next;
            head2 = head2->next;
        }

        while(carry != 0){
            int sum = carry;
            
            int node = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node);
            curr->next = temp;
            curr = curr->next;
        }

        ListNode* temp = reverse(ans->next);

        return temp;
    }
};