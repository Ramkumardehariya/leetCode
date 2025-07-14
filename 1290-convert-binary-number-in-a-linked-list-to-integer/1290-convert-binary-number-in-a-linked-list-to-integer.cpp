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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string str = "";

        while(temp != NULL){
            str += to_string(temp->val);
            temp = temp->next;
        }

        reverse(str.begin(), str.end());
        int ans = 0;
        int num = 1;
        cout<<str;

        for(int i = 0; i<str.size(); i++){
            if(str[i] == '1'){
                ans += num;
            }
            num = num*2;
        }

        return ans;
    }
};