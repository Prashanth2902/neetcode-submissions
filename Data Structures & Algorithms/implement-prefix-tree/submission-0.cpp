class TrieNode {
public:
    TrieNode* arr[26];
    bool wordEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
        wordEnd = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto c: word) {
            int idx = c - 'a';
            if(curr->arr[idx] == nullptr) {
                curr->arr[idx] = new TrieNode();
            }
            curr = curr->arr[idx];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c: word) {
            int idx = c - 'a';
            if(curr->arr[idx] == nullptr) return false;
            curr = curr->arr[idx];
        }
        return curr->wordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c: prefix) {
            int idx = c - 'a';
            if(curr->arr[idx] == nullptr) return false;
            curr = curr->arr[idx];
        }
        return true;
    }
};
