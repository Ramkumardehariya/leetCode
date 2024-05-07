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
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        stack<int> st;
        st.push(curr->val);

        while(curr->next != NULL){
            curr = curr->next;
            st.push(curr->val);
        }
        int rem = 0;
        ListNode* tail = NULL;

        while(!st.empty()){
            int num = st.top();
            st.pop();
            num = num*2;
            num += rem;
            rem = num/10;
            int num1 = num%10;
            ListNode* temp = new ListNode(num1);
            if(tail == NULL){
                tail = temp;
            }
            else{
                temp->next = tail;
                tail = temp;
            }
        }
        if(rem != 0){
            ListNode* temp = new ListNode(rem);
            temp->next = tail;
            tail = temp;
        }
        return tail;
    }
};