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
    vector<TreeNode*> solve(int start, int n){
        if(start > n){
            return {NULL};
        }
        vector<TreeNode*> ans;
        
        for(int i = start; i<=n;i++){
            for(auto left : solve(start, i-1)){
                for(auto right : solve(i+1, n)){
                    TreeNode* node = new TreeNode(i, left, right);
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};