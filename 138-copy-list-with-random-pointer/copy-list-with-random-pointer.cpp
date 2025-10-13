/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node*,Node*>mp;
        while(temp){
         int val=temp->val;
         Node* newNode=new Node(val);
         mp[temp]=newNode;
         temp=temp->next;
        }
        Node* curr=head;
        while(curr){
        mp[curr]->next=mp[curr->next];
        mp[curr]->random=mp[curr->random];
        curr=curr->next;
        }
        return mp[head];
    }
};