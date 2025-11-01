
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            int val=nums[i];
            st.insert(val);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=head;
        ListNode* temp=dummy;
        while(curr){
            int val=curr->val;
            if(st.find(val)!=st.end()){
                curr=curr->next;
                continue;
            }
            temp->next=curr;
            curr=curr->next;
            temp=temp->next;
        }
         temp->next = nullptr;
        return dummy->next; 
    }
};