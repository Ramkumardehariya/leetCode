class Solution {
    struct TrieNode {
        bool wordEnd = false;
        unordered_map<string, TrieNode*> child;
    };
public:

    void trieInsert(string folder, TrieNode* curr){

        int i = 1;

        while(i < folder.size()){
            string name;
            while(i < folder.size() && folder[i] != '/'){
                name.push_back(folder[i]);
                i++;
            }

            if(curr->wordEnd){
                return;
            }

            if(!curr->child[name]){
                curr->child[name] = new TrieNode;
            }
            curr = curr->child[name];
            i++;
        }

        curr->wordEnd = true;
    }

    void searchTitle(TrieNode* curr, vector<string> &ans, string path){
        if(!curr){
            return;
        }

        if(curr->wordEnd){
            path.pop_back();
            ans.push_back(path);
            return;
        }

        for(auto &[name,child] : curr->child){
            searchTitle(child, ans, path + name + '/');
        }
    }
    vector<string> removeSubfolders(vector<string>& folders) {
        TrieNode* root = new TrieNode;

        for(const string& folder : folders){
            trieInsert(folder, root);
        }

        vector<string> ans;

        searchTitle(root, ans, "/");

        return ans;
    }
};