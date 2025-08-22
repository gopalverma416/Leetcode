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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        stack<ListNode*> st1, st2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // push l1 into stack
        while (temp1) {
            st1.push(temp1);
            temp1 = temp1->next;
        }
        // push l2 into stack
        while (temp2) {
            st2.push(temp2);
            temp2 = temp2->next;
        }

        stack<int> result;

        // both stacks non-empty
        while (!st1.empty() || !st2.empty()) {
            int value1 = 0, value2 = 0;
            if (!st1.empty()) {
                value1 = st1.top()->val;
                st1.pop();
            }
            if (!st2.empty()) {
                value2 = st2.top()->val;
                st2.pop();
            }
            int sum = value1 + value2 + carry;
            result.push(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) result.push(carry);

        // build linked list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (!result.empty()) {
            curr->next = new ListNode(result.top());
            result.pop();
            curr = curr->next;
        }

        return dummy->next;
    }
};
