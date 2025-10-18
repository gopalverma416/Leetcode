class Solution {
public:
    TreeNode* parent; // this will store node with value x
    int X;

    int dfs(TreeNode* root, vector<int>& child) {
        if (!root) {
            return 0;
        }

        // ✅ fix 1: we should mark parent when we find the node with value X
        if (root->val == X) {
            parent = root;
        }

        // ✅ fix 2: compute left and right subtree sizes correctly
        int left = dfs(root->left, child);
        int right = dfs(root->right, child);

        // ✅ fix 3: store correct size in child array
        child[root->val] = 1 + left + right;

        return child[root->val];
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> child(n + 1, 0);
        X = x;
        parent = NULL;

        dfs(root, child);

        // ✅ fix 4: correctly get sizes of left, right, and parent parts
        int left = 0;
        if (parent && parent->left) {
            left = child[parent->left->val];
        }

        int right = 0;
        if (parent && parent->right) {
            right = child[parent->right->val];
        }

        int par = n - left - right - 1;

        int maxi = max({left, right, par});
        if (maxi > n - maxi) {
            return true;
        } else {
            return false;
        }
    }
};
