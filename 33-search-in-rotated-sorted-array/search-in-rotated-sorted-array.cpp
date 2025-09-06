class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(target==val){
                return i;
            }
        }
        return -1;
    }
};