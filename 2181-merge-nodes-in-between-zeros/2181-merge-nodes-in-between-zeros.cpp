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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* curr = ans;
        int count = 0;

        while(head != NULL){
            count += head->val;
            if(head->val == 0 && count > 0){
                ListNode* temp = new ListNode(count);
                if(curr == NULL){
                    curr = temp;
                    ans = curr;
                }
                else{
                    curr->next = temp;
                    curr = curr->next;
                }
                count = 0;
            }
            head = head->next;
        }
        return ans;
    }
};