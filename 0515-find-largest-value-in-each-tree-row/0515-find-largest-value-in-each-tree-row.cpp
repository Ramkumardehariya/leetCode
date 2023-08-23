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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        priority_queue<int> pq;
        q.push(root);
        pq.push(root->val);
        ans.push_back(pq.top());
        pq.pop();

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                auto node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    pq.push(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    pq.push(node->right->val);
                }

            }
            ans.push_back(pq.top());
            while(!pq.empty()){
                pq.pop();
            }
        }
        
        ans.pop_back();
        return ans;
    }
};