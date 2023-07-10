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

    int solve(TreeNode* root, int level){
        if(root->left == NULL && root->right == NULL){
            return level;
        }

        int ans = INT_MAX;
        if(root->left){
            ans = min(ans, solve(root->left, level+1));
        }
        if(root->right){
            ans = min(ans, solve(root->right, level+1));
        }
        return ans;
    }
        

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        return 1+solve(root, 0);
    }
};