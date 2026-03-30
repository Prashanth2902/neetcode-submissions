class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.find(endWord) == s.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++) {
                char org = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(s.count(word)) {
                        q.push({word, steps+1});
                        s.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};