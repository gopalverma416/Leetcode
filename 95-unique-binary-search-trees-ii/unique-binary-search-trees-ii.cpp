
class Solution {
private:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;

       
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTree = solve(start, i - 1);
            vector<TreeNode*> rightTree = solve(i + 1, end);

            
            for (auto left : leftTree) {
                for (auto right : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};    
        return solve(1, n);         
    }
};
