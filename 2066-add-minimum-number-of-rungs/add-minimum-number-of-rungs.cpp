class Solution {
public:
    int addRungs(vector<int>& nums, int dist) {
        int cnt=0;
        int n=nums.size();
        if(nums[0]>dist){
            cnt+=(nums[0]-1)/dist;
        }
        for(int i=0;i<n-1;i++){
            int val=nums[i];
            int next=nums[i+1];
            int diff=(next-val);
            if(diff>dist){
           cnt+=(diff-1)/dist;
            }
            
        }
        return cnt;
    }
};