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
    unordered_map<int, vector<TreeNode*>> mp;

    vector<TreeNode*> solve(int n){

        vector<TreeNode*> ans;
        if(n < 1 || n%2 == 0){
            return ans;
        }

        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        if(n == 1){
            TreeNode* node = new TreeNode(0);
            ans.push_back(node);
            return ans;
        }
        for(int i = 1; i<n; i+=2){
            vector<TreeNode*> left = solve(i);
            vector<TreeNode*> right = solve(n-i-1);

            for(auto l : left){
                for(auto r : right){
                    TreeNode* node = new TreeNode(0);

                    node->left = l;
                    node->right = r;

                    ans.push_back(node);
                }
            }
        }
        mp[n] = ans;
        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};