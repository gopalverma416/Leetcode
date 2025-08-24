class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

       
        for(int i=1; i<left; i++) {
            prev = prev->next;
        }

      
        stack<ListNode*> st;
        ListNode* curr = prev->next;
        for(int i=left; i<=right; i++) {
            st.push(curr);
            curr = curr->next;
        }

        
        ListNode* tail = curr; 
        while(!st.empty()) {
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }

        
        prev->next = tail;

        return dummy.next;
    }
};
