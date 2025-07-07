class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        vector<int>arr;
        while(!pq.empty()){
            int first=pq.top();
            pq.pop();
            if(!pq.empty()){
              int second=pq.top();
               pq.pop();
               arr.push_back(second);
               arr.push_back(first);
            }else{
                arr.push_back(first);
            }
           

        }
        return arr;
    }
};