class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* temp = head;
        stack<ListNode*> st;

        // collect nodes in stack
        while (temp) {
            st.push(temp);
            temp = temp->next;
        }

        int n = st.size();
        temp = head;

        for (int i = 0; i < n / 2; i++) {
            ListNode* last = st.top(); 
            st.pop();

            // weave
            last->next = temp->next;
            temp->next = last;
            temp = last->next;
        }

        temp->next = nullptr; // terminate
    }
};
