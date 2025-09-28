class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        stack<int>st;
        vector<int>res(m,-1);
        for(int i=m-1;i>=0;i--){
            int val=nums2[i];
            while(!st.empty() && st.top()<=val){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(val);
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val1=nums1[i];
                int val2=nums2[j];
                if(val1==val2){
                    nums1[i]=j;
                    break;
                }
            }
         }
         vector<int>ans;
         for(int i=0;i<n;i++){
           int idx=nums1[i];
           ans.push_back(res[idx]);
         }
      return ans;
    }
};