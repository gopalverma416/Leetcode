class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int idx=1;
        int cnt=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int val=nums[i];
            if(val==nums[i-1]){
                continue;
            }
            if(val!=nums[i-1]){
                cnt++;
                nums[idx]=val;
                idx++;
            }
        }
        return cnt;
    }
};