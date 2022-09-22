class Trie {
public:
    struct node{
        node* child[26] = {};
        bool isleaf = false;
    };
    
    node root;
    
    Trie() {
        
    }
    
    void insert(string word) {
        node* cur = &root;
        for(char c:word){
            int x = c- 'a';
            if(!cur->child[x]){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->isleaf = true;
    }
    
    bool search(string word) {
        node* cur = &root;
        for(char c:word)
        {
            int x = c-'a';
            if(!cur->child[x])
                return false;
            cur = cur->child[x];
        }
        if(cur->isleaf)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        node* cur = &root;
        for(char c:prefix)
        {
            int x = c-'a';
            if(!cur->child[x])
                return false;
            cur = cur->child[x];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */