/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
    private: 
    void solve(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }

public:
    vector<int> inorder;
    int idx = 0;
    BSTIterator(TreeNode* root) { 
        solve(root, inorder);
    }

    int next() {
      return inorder[idx++];
    }

    bool hasNext() {
        int n=inorder.size();
        return idx<n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */