class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;  // ✅ edge case: empty tree

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* prev = NULL;
            int size = q.size();

            for(int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();

                if(prev) prev->next = curr;
                prev = curr;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            prev->next = NULL; // last node in level
        }
        return root;
    }
};
