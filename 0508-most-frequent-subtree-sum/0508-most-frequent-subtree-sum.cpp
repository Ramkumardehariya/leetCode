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
    int solve(TreeNode* root, unordered_map<int,int> &mp, int &x){
        if(root == NULL){
            return 0;
        }

        int l = solve(root->left, mp, x);
        int r = solve(root->right, mp, x);
        x = max(x, ++mp[root->val + l + r]);
        return root->val+l+r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x = -1;
        vector<int> ans;
        unordered_map<int,int> mp;

        solve(root, mp, x);
        
        for(auto it : mp){
            if(it.second == x){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};