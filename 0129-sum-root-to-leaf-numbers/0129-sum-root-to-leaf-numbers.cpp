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
    int res = 0;
    void helper(TreeNode *node, int val)
    { 
        val = val * 10 + node -> val;
        //the base case
        if(!node -> right && !node -> left)
        {
            res += val;
            return;
        }
        //jump to the left child
        if(node->left)
            helper(node -> left, val);
        //jump to the right child
        if(node->right)
            helper(node -> right, val);
        return;
    }
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return res;  
    }
};