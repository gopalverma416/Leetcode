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
    using P = pair<int, ListNode*>;
    ListNode* sortList(ListNode* head) {
        priority_queue<P, vector<P>, greater<P>> pq;
        ListNode* temp = head;
        while (temp) {
            pq.push({temp->val, temp});
            temp=temp->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while (!pq.empty()) {
            auto [val, Node] = pq.top();
            pq.pop();
            ans->next = Node;
            ans = ans->next;
            ans->next=nullptr;
        }
        return dummy->next;
    }
};