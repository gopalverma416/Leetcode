class Solution {
private:
    bool solve(TreeNode* root, TreeNode* target) {
        if (root == NULL) return false;
        if (root == target) return true;

        // Check in left or right subtree
        return solve(root->left, target) || solve(root->right, target);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        // If root is p or q, return root
        if (root == p || root == q) return root;

        bool isPInLeft = solve(root->left, p);
        bool isQInLeft = solve(root->left, q);

        if (isPInLeft && isQInLeft) {
            // Both in left subtree
            return lowestCommonAncestor(root->left, p, q);
        } else if (!isPInLeft && !isQInLeft) {
            // Both in right subtree
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // One in left, one in right => current node is LCA
            return root;
        }
    }
};
