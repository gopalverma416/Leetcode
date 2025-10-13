
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    void parent(TreeNode* root){
        TreeNode* temp=root;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty()){
          TreeNode* temp=pq.front();
          pq.pop();
          if(temp->left){
            pq.push(temp->left);
            mp[temp->left]=temp;
          }  
          if(temp->right){
            pq.push(temp->right);
            mp[temp->right]=temp;
          }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        parent(root);
        queue<pair<int,TreeNode*>>pq;
        pq.push({0,target});
       unordered_map<TreeNode*,bool>visited;
         visited[target] = true; 
        while(!pq.empty()){
            auto [len,curr]=pq.front();
            pq.pop();
            visited[curr]=true;
            if(len==k){
                ans.push_back(curr->val);
                continue;
            }
            if(len>k){
                continue;
            }
            if(curr->left && !visited[curr->left]){
                pq.push({len+1,curr->left});
            }
            if(curr->right && !visited[curr->right]){
                pq.push({len+1,curr->right});
            }
            if(mp.find(curr)!=mp.end() && !visited[mp[curr]]){
                pq.push({len+1,mp[curr]});
            }
        }
       return ans;
    }
};