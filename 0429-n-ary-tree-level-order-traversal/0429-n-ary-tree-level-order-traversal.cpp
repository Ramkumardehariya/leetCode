/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<Node*> pq;
        pq.push(root);

        while(!pq.empty()){
            int n = pq.size();
            vector<int> temp;
            
            for(int i = 0; i<n; i++){
                Node* node = pq.front();
                pq.pop();

                for(auto child : node->children){
                    pq.push(child);
                }

                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};