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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;
        while(temp){
           int val=temp->val;
           ans.push_back(val);
           temp=temp->next;
        }
        int n=ans.size();
        vector<int>critical;
        for(int i=1;i+1<n;i++){
            if(ans[i-1]>ans[i] && ans[i]<ans[i+1]){
                critical.push_back(i-1);
            }
            if(ans[i-1]<ans[i] && ans[i]>ans[i+1]){
                critical.push_back(i-1);
            }
        }
        if(critical.size()<2){
            return {-1,-1};
        }
        sort(critical.begin(),critical.end());
        int sz=critical.size();
        int maxi=abs(critical[0]-critical[sz-1]);
        int mini=INT_MAX;
        for(int i=1;i<sz;i++){
          int diff=critical[i]-critical[i-1];
          mini=min(mini,diff);
        }
         return {mini,maxi};
    }
};