class Node {
public:
    Node* arr[26];
    bool wordEnd;

    Node() {
        wordEnd = false;
        for(int i=0;i<26;i++) arr[i] = nullptr;
    }
};

class WordDictionary {
public:

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (auto c: word) {
            int idx = c - 'a';
            if(curr->arr[idx] == nullptr) {
                curr->arr[idx] = new Node();
            }
            curr = curr->arr[idx];
        }
        curr->wordEnd = true;
    }
    
    bool dfs(int idx, string& word, Node* curr) {
        for(int i = idx;i<word.size();i++) {
            if(word[i] == '.') {
                for(int j=0;j<26;j++) {
                    if(curr->arr[j] != nullptr && 
                    dfs(i+1, word, curr->arr[j])) {
                        return true;
                    } 
                }
                return false;
            } else {
                int idx = word[i] - 'a';
                if (curr->arr[idx] == nullptr) return false;
                curr = curr->arr[idx];
            }
        }
        return curr->wordEnd;
    }

    bool search(string word) {
        Node* curr = root;
        return dfs(0, word, curr);
    }
};
