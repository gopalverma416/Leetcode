class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long >prefix(n+1,0);
      
        for(int i=0;i<n;i++){
         prefix[i+1]=prefix[i]+nums[i];
        }
        int right=0;
        int mini=n+1;
         deque<int>dq;
         for(int right=0;right<=n;right++){
            while(!dq.empty() &&  prefix[right]-prefix[dq.front()]>=k){
                mini=min(mini,right-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[right]<=prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
         }
         return mini==n+1 ? -1 :mini;
    }
};