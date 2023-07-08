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
    //     ans.push_back(root->val);
    //     solve(root->right);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        //recursive
        // solve(root);

        //iterative
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty() == true){
                    break;
                }
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};