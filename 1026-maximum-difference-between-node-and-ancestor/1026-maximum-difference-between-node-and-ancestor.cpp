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
    int solve(TreeNode* root, int maxi, int mini){
        if(root == NULL){
            return maxi-mini;
        }

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        int left = solve(root->left, maxi,mini);
        int right = solve(root->right, maxi, mini);

        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val,root->val);
    }
};