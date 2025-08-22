
class Solution {
    void dfs(TreeNode* root, int val, int depth, int curr) {
        if (!root) return;

        if (curr == depth - 1) {
            // insert new left
            TreeNode* tempL = root->left;
            root->left = new TreeNode(val);
            root->left->left = tempL;

            // insert new right
            TreeNode* tempR = root->right;
            root->right = new TreeNode(val);
            root->right->right = tempR;
        } else {
            dfs(root->left, val, depth, curr + 1);
            dfs(root->right, val, depth, curr + 1);
        }
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, val, depth, 1);  
        return root;
    }
};
