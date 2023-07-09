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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> topo;

        topo.push({root,{0,0}});

        while(!topo.empty()){
            auto p = topo.front();
            topo.pop();
            TreeNode* node = p.first;
            int lvl = p.second.second;
            int hd = p.second.first;

            nodes[hd][lvl].insert(node->val);
            if(node->left){
                topo.push({node->left, {hd-1, lvl+1}});
            }
            if(node->right){
                topo.push({node->right, {hd+1, lvl+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> temp;
            for(auto q : p.second){
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};