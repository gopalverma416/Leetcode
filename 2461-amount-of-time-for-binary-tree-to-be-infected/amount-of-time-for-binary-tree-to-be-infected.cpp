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
     unordered_map<TreeNode*,TreeNode*>mp;
     TreeNode* starti;
    void dfs(TreeNode* root,int temp){
        int val=root->val;
        if(val==temp){
            starti=root;
        }
        if(root->left){
            mp[root->left]=root;
            dfs(root->left,temp);
        }
        if(root->right){
            mp[root->right]=root;
            dfs(root->right,temp);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        int timer=0;
        
        using P=pair<int,TreeNode*>;
        queue<P>pq;
        pq.push({0,starti});
        unordered_map<TreeNode*,bool>vis;
        
        while(!pq.empty()){
            auto temp=pq.front();
            pq.pop();
            int time=temp.first;
            timer=max(timer,time);
            TreeNode* curr=temp.second;
            vis[curr]=true;
            if(curr->left && vis.find(curr->left)==vis.end()){
               
                pq.push({time+1,curr->left});
            }
            if(curr->right && vis.find(curr->right)==vis.end()){
                pq.push({time+1,curr->right});
            }
            if(mp.find(curr)!=mp.end()){
                TreeNode* par=mp[curr];
                 if(par && vis.find(par)==vis.end()){
                pq.push({time+1,par});
            }
            }
        }
       return timer;
    }
};