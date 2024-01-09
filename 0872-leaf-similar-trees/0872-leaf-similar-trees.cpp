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
    vector<int> temp1;
    vector<int> temp2;

    void solve1(TreeNode* root){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            temp1.push_back(root->val);
        }
        solve1(root->left);
        solve1(root->right);
    }

    void solve2(TreeNode* root){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            temp2.push_back(root->val);
        }
        solve2(root->left);
        solve2(root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve1(root1);
        solve2(root2);
        if(temp1 == temp2){
            return true;
        }

        return false;
    }
};