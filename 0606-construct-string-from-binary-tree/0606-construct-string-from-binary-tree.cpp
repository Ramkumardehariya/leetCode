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
    string ans = "";

    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        ans += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            return;
        }

        ans.push_back('(');
        solve(root->left);
        ans.push_back(')');

        if(root->right) ans.push_back('(');
        solve(root->right);
        if(root->right) ans.push_back(')');
    }
    string tree2str(TreeNode* root) {
        solve(root);
        return ans;

    }
};