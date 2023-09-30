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
    void solve(TreeNode* root, int val, int d){
        if(root==NULL){
            return;
        }
        if(d == 1){
            TreeNode *tl = root->left;
            TreeNode *tr = root->right;

            root->left = new TreeNode(val, tl, NULL);
            root->right = new TreeNode(val, NULL, tr);
            return;
        }

        solve(root->left , val, d-1);
        solve(root->right, val, d-1);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }

        solve(root, val, depth-1);
        return root;
    }
};