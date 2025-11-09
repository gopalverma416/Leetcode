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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> pq;
        pq.push(root);
        int level = 0;
        while (!pq.empty()) {
            int sz = pq.size();
            int last = -1;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = pq.front();
                pq.pop();
                int val = node->val;
                if (level % 2 == 0) {
                    if ((val > last || last == -1) && (val % 2 != 0)) {
                        if (node->left) {
                            pq.push(node->left);
                        }
                        if (node->right) {
                            pq.push(node->right);
                        }
                    } else {
                        return false;
                    }
                    last=val;
                }else{
                      if ((val < last || last == -1) && (val % 2 == 0)) {
                        if (node->left) {
                            pq.push(node->left);
                        }
                        if (node->right) {
                            pq.push(node->right);
                        }
                    } else {
                        return false;
                    }
                    last=val;
                }
            }
            level++;
        }
        return true;
    }
};