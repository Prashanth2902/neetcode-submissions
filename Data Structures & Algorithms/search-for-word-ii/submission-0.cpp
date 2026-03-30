class Node {
public:
    Node* arr[26];
    string currWord;

    Node() {
        currWord = "";
        for(int i=0;i<26;i++) arr[i] = nullptr;
    }
};

class Solution {
public:

    void insertWord(Node* root, string word) {
        Node* curr = root;
        for(auto c: word) {
            int idx = c - 'a';
            if(curr->arr[idx] == nullptr) {
                curr->arr[idx] = new Node();
            }
            curr = curr->arr[idx];
        }
        curr->currWord = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, vector<string>& ans, Node* root) {
        int rows = board.size();
        int cols = board[0].size();

        if(min(r,c) < 0 || r >= rows || c >= cols || board[r][c] == '#') return;
        
        char letter = board[r][c];
        int idx = letter - 'a';

        if(root->arr[idx] == nullptr) return;

        Node* nextNode = root->arr[idx];

        if(nextNode->currWord != "") {
            ans.push_back(nextNode->currWord);
            nextNode->currWord = "";
        }

        board[r][c] = '#';

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};

        for(int i=0;i<4;i++) {
            int nr = r+dr[i];
            int nc = c+dc[i];
            dfs(board, nr, nc, ans, nextNode);
        }

        board[r][c] = letter;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        Node* root = new Node();
        for(string word: words) insertWord(root, word);

        int rows = board.size();
        int cols = board[0].size();
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++){
                dfs(board, r, c, ans, root);
            }
        }
        return ans;
    }
};
