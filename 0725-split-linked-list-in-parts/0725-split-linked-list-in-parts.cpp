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
    int count(ListNode* head){
        ListNode* curr = head;
        int ans = 0;
        while(curr != NULL){
            curr = curr->next;
            ans++;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head == NULL){
            return vector<ListNode*>(k, NULL);
        }
        vector<ListNode*> ans;
        int size = count(head);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int amount = size/k;
        int additional = size%k;

        int count = amount + (additional > 0 ? 1 : 0);
        if(additional > 0){
            additional--;
        }

        for(int i = 0; i<size; i++){
           
           if(i == count){
               prev->next = NULL;
               ans.push_back(curr);
               count += amount + (additional>0 ? 1 : 0);
               if(additional > 0){
                   additional--;
               }
           }

           prev = curr;
           curr = curr->next;

           if(i==0){
               ans.push_back(head);
           }
        }

        while(ans.size() < k){
            ans.push_back(NULL);
        }
        return ans;
    }
};