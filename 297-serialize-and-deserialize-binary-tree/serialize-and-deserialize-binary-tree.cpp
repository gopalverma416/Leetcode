/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";  // FIX: handle empty tree

        queue<TreeNode*> pq;
        pq.push(root);
        vector<string> ans;  // FIX: use string instead of char

        ans.push_back(to_string(root->val)); // FIX: directly push string

        while (!pq.empty()) {
            TreeNode* temp = pq.front();
            pq.pop();

            if (temp->left) {
                pq.push(temp->left);
                ans.push_back(to_string(temp->left->val)); // FIX: use temp not root
            } else {
                ans.push_back("#"); // FIX: push string not char
            }

            if (temp->right) {
                pq.push(temp->right);
                ans.push_back(to_string(temp->right->val)); // FIX: use temp not root
            } else {
                ans.push_back("#");
            }
        }

        string result = "";
        for (int i = 0; i < ans.size(); i++) {
            result += ans[i];
            if (i != ans.size() - 1) {
                result += ','; // FIX: missing semicolon
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL; // FIX: handle empty tree

        stringstream ss(data);
        string token;
        vector<string> nodes;

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0])); // FIX: corrected new TreeNode creation
        queue<TreeNode*> pq;
        pq.push(root);
        int idx = 1;

        while (!pq.empty() && idx < nodes.size()) {
            TreeNode* curr = pq.front();
            pq.pop();

            if (nodes[idx] != "#") {
                curr->left = new TreeNode(stoi(nodes[idx])); // FIX
                pq.push(curr->left);
            }
            idx++;

            if (idx < nodes.size() && nodes[idx] != "#") {
                curr->right = new TreeNode(stoi(nodes[idx])); // FIX
                pq.push(curr->right);
            }
            idx++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
