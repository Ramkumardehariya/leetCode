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
    void solve(ListNode* l1, ListNode* l2, ListNode* &head,ListNode* tail, int rem){
        if(l1 == NULL && l2 == NULL && rem == 0){
            return;
        }

        int first = 0;
        int second = 0;
        
        if(l1 != NULL){
            first = l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            second = l2->val;
            l2 = l2->next;
        }
        int sum = first + second + rem;
        rem = sum/10;
        int num = sum%10;
        ListNode* temp = new ListNode(num);
        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        solve(l1, l2, head, tail, rem);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        solve(l1, l2, head,tail, rem);

        return head;
    }
};