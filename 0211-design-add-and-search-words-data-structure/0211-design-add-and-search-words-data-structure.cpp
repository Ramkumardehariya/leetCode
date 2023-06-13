class TrieNode{
    public:
    TrieNode* children[26];
    bool isTerminal;
    char data;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


class WordDictionary {
public:

    //TLE
    // unordered_map<int,vector<string>> words;

    // WordDictionary() {

    // }
    
    // void addWord(string word) {
        // words[word.size()].push_back(word);
    // }

    // bool isEqual(string a, string b){
        // for(int i = 0; i<a.size(); i++){
        //     if(b[i] == '.'){
        //         continue;
        //     }
        //     if(a[i] != b[i]){
        //         return false;
        //     }
        // }
        // return true;
    // }
    
    // bool search(string word) {
        // for(auto s: words[word.size()]){
        //     if(isEqual(s,word)){
        //         return true;
        //     }
        // }
        // return false;
    // }


    // TrieNode* root;

    // WordDictionary() {
    //     root = new TrieNode('\0');
    // }

    // void add(TrieNode* root, string word){
    //     if(word.length() == 0){
    //         root->isTerminal = true;
    //         return;
    //     }

    //     int index = word[0]-'a';
    //     TrieNode* child;

    //     if(root->children[index] != NULL){
    //         child = root->children[index];
    //     }
    //     else{
    //         child = new TrieNode(word[0]);
    //         root->children[index] = child;
    //     }

    //     add(root, word.substr(1));

    // }
    
    // void addWord(string word) {
    //     add(root, word);
    // }

    // bool searchUtil(TrieNode* root, string word){
    //     if(word.length() == 0){
    //         return root->isTerminal;
    //         return true;
    //     }

    //     int index;

    //     if(word[0] != '.'){
    //         index = word[0] - 'a';
    //     }
 
    //     TrieNode* child;

    //     if(word[0] == '.'){
    //         // child = root->children[index];
    //         // root = root->child;
    //         // if(root->children[index] != NULL)
    //         if(word[word.size()] != word[1]){
    //             index = word[1]-'a';
    //             child = root->children[index];
    //             return searchUtil(child, word.substr(1));
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     else if(root->children[index] != NULL){
    //         child = root->children[index];
    //     }
    //     else{
    //         return false;
    //     }

    //     return searchUtil(child, word.substr(1));
    // }

    // bool search(string word) {
    //     return searchUtil(root, word);
    // }


    class Trie{
        public:
        Trie* child[26];
        bool isEnd = false;
    };
    
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *cur = root;
        for(auto &ch : word){
            int pos = ch-'a';
            if(cur->child[pos]==NULL) cur->child[pos] = new Trie();
            cur=cur->child[pos];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        Trie *cur = root;
        return find(word,0,cur);
    }
    
    bool find(string &word, int idx, Trie* cur){
        if(idx == word.size()) return cur->isEnd;
		
        if(word[idx]=='.'){
            for(int i=0; i<26; ++i){
                if(cur->child[i] && find(word, idx+1, cur->child[i])) return true;
            }
        }else{
            int i = word[idx]-'a';
            if(cur->child[i] && find(word, idx+1, cur->child[i])) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */