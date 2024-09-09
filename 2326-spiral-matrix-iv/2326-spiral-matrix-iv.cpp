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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<int> temp;

        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;

        ListNode* curr = head;

        while(curr != NULL){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        int i = 0;
        while(i < temp.size()){
            for(int j = left; j<=right; j++){
                ans[top][j] = temp[i];
                i++;
                if(i >= temp.size()){
                    break;
                }
            }
            top++;
            if(i >= temp.size()){
                break;
            }

            for(int j = top; j<=bottom; j++){
                ans[j][right] = temp[i];
                i++;
                if(i >= temp.size()){
                    break;
                }
            }
            right--;
            if(i >= temp.size()){
                break;
            }

            for(int j = right; j>=left; j--){
                ans[bottom][j] = temp[i];
                i++;
                if(i >= temp.size()){
                    break;
                }
            }
            bottom--;
            if(i >= temp.size()){
                break;
            }
            for(int j = bottom; j>=top; j--){
                ans[j][left] = temp[i];
                i++;
                if(i >= temp.size()){
                    break;
                }
            }
            left++;
        }

        return ans;
    }
};