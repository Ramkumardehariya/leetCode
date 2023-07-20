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
    ListNode* temp = NULL;
    Solution(ListNode* head) {
        temp = head;
    }

    int getSize(ListNode* head){
        int count = 0;

        ListNode* curr = head;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }

    int getRandom() {
        int size = getSize(temp);
        int random = rand() % size;
        ListNode* curr = temp;

        for(int i = 0; i<random; i++){
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */