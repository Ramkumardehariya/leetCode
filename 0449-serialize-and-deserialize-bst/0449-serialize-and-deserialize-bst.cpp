/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void solve(TreeNode* root, string &tree)
    {
        if(root==NULL)
        {
            tree += "#,";
            return;
        }
        
        tree += to_string(root->val)+",";
        solve(root->left,tree);
        solve(root->right,tree);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree = "";
        solve(root,tree);
        return tree;
        
    }
    
    TreeNode* solve1(string &data, int &i)
    {
        if(i==data.size() || data[i]=='#')
         {
            i+=2;
            return NULL;
        }
        
        int val =0;
        while(data[i]!=',')
        {
            val = val*10 + (data[i]-'0');
            i++;
        }
        
        TreeNode* root = new TreeNode(val);
        i++;
        root->left = solve1(data,i);
        root->right = solve1(data,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i=0;
        return solve1(data,i);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;