class Node {
public:

    int sum;
    int leftIdx, rightIdx;
    Node* left;
    Node* right;

    Node(int sum, int l, int r) {
        this->sum = sum;
        leftIdx = l;
        rightIdx = r;
        left = nullptr;
        right = nullptr;
    }
};


class SegmentTree {
public:

    Node* root;

    SegmentTree(vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);
    }

    Node* build(vector<int>& nums, int l, int r) {
        
        if(l == r) {
            return new Node(nums[l], l, r);
        }

        int m = (l+r)/2;
        Node* root = new Node(0, l, r);
        root->left = build(nums, l, m);
        root->right = build(nums, m+1, r);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    void updateHelper(Node* root, int index, int val) {
        if(root->leftIdx == root->rightIdx) {
            root->sum = val;
            return;
        }

        int m = (root->leftIdx + root->rightIdx) / 2;
        if(index > m) {
            updateHelper(root->right, index, val);
        } else {
            updateHelper(root->left, index, val);
        }
        root->sum = root->left->sum + root->right->sum;

    }

    void update(int index, int val) {
        updateHelper(root, index, val);
    }
    
    int queryHelper(Node* root, int l, int r) {
        if(l <= root->leftIdx && root->rightIdx <= r) {
            return root->sum;
        }

        if(r < root->leftIdx || l > root->rightIdx) return 0;

        return queryHelper(root->left, l, r) + queryHelper(root->right, l, r);
    }

    int query(int L, int R) {
        return queryHelper(root, L, R);
    }
};
