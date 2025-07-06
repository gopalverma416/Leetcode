class Solution {
    void leaf(TreeNode* root, vector<int>& num) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            num.push_back(root->val);
            return;
        }

        leaf(root->left, num);
        leaf(root->right, num);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        leaf(root1, nums1);
        leaf(root2, nums2);
        return nums1 == nums2; // clean comparison
    }
};
