/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(q.size() != 0){
            int size = q.size();

            for(int i = 0; i<size; i++){
                auto it = q.front();
                q.pop();
                
                if(it->right){
                    q.push(it->right);
                }
                if(it->left){
                    q.push(it->left);
                }
                if(q.size() == 1){
                    ans = q.front()->val;
                }
            }
        }
        return ans;
    }
};