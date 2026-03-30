/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:

    

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;

        for(auto list: lists) {
            if(list) {
                heap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!heap.empty()) {
            ListNode* currNode = heap.top();
            heap.pop();
            curr->next = currNode;
            curr = curr->next;
            if(currNode->next) {
                heap.push(currNode->next);
            }
        }
        return dummy->next;
    }
};
