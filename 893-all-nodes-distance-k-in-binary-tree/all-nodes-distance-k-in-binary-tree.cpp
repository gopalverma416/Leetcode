/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* curr;

    void dfs(TreeNode* node, TreeNode* prev,
             unordered_map<TreeNode*, TreeNode*>& parent,
             vector<int>& ans, int cnt, int k) {

        if (!node) return;
        if (cnt == k) {
            ans.push_back(node->val);
            return;
        }

        if (node->left && node->left != prev)
            dfs(node->left, node, parent, ans, cnt + 1, k);

        if (node->right && node->right != prev)
            dfs(node->right, node, parent, ans, cnt + 1, k);

        if (parent[node] && parent[node] != prev)
            dfs(parent[node], node, parent, ans, cnt + 1, k);
    }

    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target) {
        queue<TreeNode*> pq;
        pq.push(root);
        parent[root] = nullptr;
        while (!pq.empty()) {
            TreeNode* node = pq.front();
            pq.pop();
            if (node == target) {
                curr = target;
            }
            if (node->left) {
                parent[node->left] = node;
                pq.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                pq.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, parent, target);
        vector<int> ans;
        dfs(curr, nullptr, parent, ans, 0, k);
        return ans;
    }
};
