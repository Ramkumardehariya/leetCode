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
    void reorderList(ListNode* head) {

        if(head== NULL || head->next == NULL || head->next->next == NULL){
            return;
        }
        ListNode* curr = head;
        vector<int> temp;

        while(curr != NULL){
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;
        int j = temp.size()-1;
        ListNode* prev = NULL;
        ListNode* curr2 = NULL;

        while(i < j){
            ListNode* node = new ListNode(temp[i]);
            if(prev == NULL){
                prev = node;
                curr2 = node;
            }
            else{
                curr2->next = node;
                curr2 = curr2->next;
            }
            // curr2 = curr2->next;
            ListNode* node2 = new ListNode(temp[j]);
            curr2->next = node2;
            curr2 = curr2->next;
            i++;
            j--;
        }

        if(temp.size()%2 != 0){
            ListNode* node = new ListNode(temp[i]);
            curr2->next = node;
        }

        head->next = NULL;
        head->next = prev->next;
    }
};