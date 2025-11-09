/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
    unordered_map<int,ListNode*>mp;
    int n;
    Solution(ListNode* head) {
         int num=1;
         ListNode* curr=head;
         while(curr){
            mp[num]=curr;
            num++;
            curr=curr->next;
         }
           n = num - 1;
    }
    
    int getRandom() {
        int randomIndex = rand() % n + 1;   
        return mp[randomIndex]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */