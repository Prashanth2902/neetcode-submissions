/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* head, unordered_map<Node*, Node*>& copyMap) {
        if(!head) return nullptr;
        if(copyMap.count(head)) return copyMap[head];

        Node* copy = new Node(head->val);
        copyMap[head] = copy;
        copy->next = dfs(head->next, copyMap);
        copy->random = copyMap[head->random];
        return copy;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyMap;
        return dfs(head, copyMap);
    }
};
