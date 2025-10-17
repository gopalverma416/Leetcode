/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>pq;
        if(!root){
            return {};
        }
        pq.push(root);
        vector<int>ans;
        while(!pq.empty()){
            int sz=pq.size();
            for(int i=0;i<sz;i++){
                TreeNode* temp=pq.front();
                pq.pop();
                if(i==sz-1){
                    ans.push_back(temp->val);
                }
                if(temp->left){
                    pq.push(temp->left);
                }
                if(temp->right){
                    pq.push(temp->right);
                }
            }
        }
        return ans;
    }
};