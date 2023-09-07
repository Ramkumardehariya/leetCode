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

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* farward = curr->next;
        while(curr != NULL){
            farward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = farward;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        int count = 1;
        while(count != left){
            prev = curr;
            curr = curr->next;
            count++;
        }

        ListNode* start = curr;

        while(count != right){
            curr = curr->next;
            count++;
        }

        ListNode* rest = curr->next;
        curr->next = NULL;

        ListNode* newHead = reverse(start);

        if(prev != NULL){
            prev->next = newHead;
        }

        curr = newHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = rest;


        if(left == 1){
            return newHead;
        }
        else{
            return head;
        }

    }
};