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
    int ans;

    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return {-1, 0};
        }
        int l = 0;
        int r = 0;

        pair<int,int> lp = solve(root->left);
        pair<int,int> lr = solve(root->right);

        if(lp.first != -1){
            l = lp.first;
        }
        if(lr.first != -1){
            r = lr.first;
        }

        int res = (root->val+l+r)/(1+lp.second+lr.second);

        if(res == root->val){
            ans++;
        }

        return {root->val+l+r, 1+lp.second+lr.second};
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};