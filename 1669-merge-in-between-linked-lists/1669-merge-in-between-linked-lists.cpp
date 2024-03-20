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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = NULL;
        ListNode* curr = list1;
        ListNode* Next = list1->next;

        int count = 1;
        while(count != a){
            prev = curr;
            curr = Next;
            Next = Next->next;
            count++;
        }
        curr->next = NULL;
        curr->next = list2;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }

        while(count != b){
            Next = Next->next;
            count++;
        }
        curr->next = Next->next;

        return list1;
    }
};