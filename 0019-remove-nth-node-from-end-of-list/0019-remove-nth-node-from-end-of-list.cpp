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
    void solve(ListNode* prev, ListNode* curr, int &n, ListNode* &head){
        if(curr == NULL){
            return;
        }
        solve(curr, curr->next, n, head);
        n--;
        if(n == 0){
            if(prev){
                prev->next = curr->next;
            }
            else{
                head = curr->next;
            }
            delete curr;
        }

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        solve(NULL, head, n, head);
        return head;
    }
};