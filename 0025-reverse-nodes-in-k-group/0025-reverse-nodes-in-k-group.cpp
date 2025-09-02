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
    int countNode(ListNode* curr, int k){
        int count = 0;
        while(curr != NULL){
            curr = curr->next;
            count++;
            if(count >= k){
                break;
            }
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        int nodeCount = countNode(head, k);
        if(nodeCount < k){
            return head;
        }
        int count = 0;

        while(curr != NULL && count != k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(curr != NULL){
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};