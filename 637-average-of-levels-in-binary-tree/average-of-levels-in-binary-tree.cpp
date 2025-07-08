
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> pq;
        pq.push(root);
        while (!pq.empty()) {
            int size = pq.size();
            double total = 0;
            int cnt = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = pq.front();
                pq.pop();
                total+= temp->val;
                if (temp->left != NULL) {
                    pq.push(temp->left);
                }
                if (temp->right != NULL) {
                    pq.push(temp->right);
                }
              
               
            }
            ans.push_back(total / size);
        }
        return ans;
    }
};