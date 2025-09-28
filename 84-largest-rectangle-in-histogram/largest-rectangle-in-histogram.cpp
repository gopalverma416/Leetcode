class Solution {
private:
    vector<int> prevSmaller(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>res(n,-1);
        for(int i=0;i<n;i++){
            int val=heights[i];
            while(!st.empty() && heights[st.top()]>=val){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(i);
        }
    return res;
    }
    vector<int> nextSmaller(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>res(n,-1);
        for(int i=n-1;i>=0;i--){
            int val=heights[i];
            while(!st.empty() && heights[st.top()]>=val){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(i);
        }
    return res;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
         vector<int> prev=prevSmaller(heights);
         vector<int> next=nextSmaller(heights);
         int maxi=INT_MIN;
         int area=0;
         for(int i=0;i<n;i++){
            int prevIdx=prev[i];
            int nextIdx=next[i];
             if(nextIdx==-1){
                nextIdx=n;
             }
             int len=nextIdx-prevIdx-1;
             int val=heights[i];
             area=(len*val);
             maxi=max(maxi,area);
         }
         return maxi;
     }
};