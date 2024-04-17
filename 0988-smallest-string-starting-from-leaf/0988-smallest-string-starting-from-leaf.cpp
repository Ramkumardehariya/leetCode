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
    string path;
    priority_queue<string, vector<string>, greater<string>>pq;
    void paths(TreeNode* root)
    {
        if(!root) return;

        char ch = root->val +'a';
        path.insert(path.begin(), ch);
        if(!root->left and !root->right) pq.push(path);
        
        paths(root->left);
        paths(root->right);

        path.erase(path.begin());
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        paths(root);
        return pq.top();
    }
};