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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> temp;
        ListNode* curr = head;
        set<int> st;
        for(int i = 0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        while(curr != NULL){
            int num = curr->val;
            if(st.find(num) == st.end()){
                temp.push_back(num);
            }
            curr = curr->next;
        }

        int i = 0;
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        cout<<temp.size();

        while(i < temp.size()){
            ListNode* Node = new ListNode(temp[i]);
            if(ans == NULL){
                ans = Node;
                tail = Node;
            }
            else{
                tail->next = Node;
                tail = tail->next;
            }
            i++;
        }
        return ans;
    }
};