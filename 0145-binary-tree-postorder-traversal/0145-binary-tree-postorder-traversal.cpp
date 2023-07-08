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
    // vector<int> ans;
    // void solve(TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }
    //     solve(root->left);
    //     solve(root->right);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // solve(root);

        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            if(root->left){
                st1.push(root->left);
            }
            if(root->right){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};