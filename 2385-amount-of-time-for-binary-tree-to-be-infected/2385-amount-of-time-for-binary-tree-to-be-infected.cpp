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
    int maxi = INT_MIN;

    int solve(TreeNode* root, int start, bool isStartNode){
        if(root == NULL){
            return 0;
        }

        if(root->val == start && isStartNode){
            maxi = max(maxi, solve(root, start, false) -1);
            return -1;
        }

        int leftHeight = solve(root->left, start, isStartNode);
        int rightHeight = solve(root->right, start, isStartNode);

        if(leftHeight < 0 || rightHeight < 0){
            maxi = max(maxi, abs(leftHeight) + abs(rightHeight));
            return min(leftHeight,rightHeight)-1;
        }

        return max(leftHeight,rightHeight)+1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int height = solve(root, start, true);
        return maxi;
    }
};