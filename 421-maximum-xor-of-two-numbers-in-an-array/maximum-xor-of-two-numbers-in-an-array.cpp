
struct Node {
    Node* children[2];
    Node() {
        children[0] = NULL;
        children[1] = NULL;
    }
};
class Solution {
    Node* root;
  
    void insert(int num) {
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->children[bit]==NULL){
                node->children[bit]=new Node();
            }
            node=node->children[bit];
        }
    }
    int getMax(int num){
        int maxXor=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num >> i) & 1;
            if(node->children[1-bit]){
                maxXor |=(1<<i);
                node=node->children[1-bit];
            }else{
                node=node->children[bit];
            }
        }
        return maxXor;
    }
public:
      Solution() { root = new Node(); }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            insert(val);
        }
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int val=nums[i];
            ans=getMax(val);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};