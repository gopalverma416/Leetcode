class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int req = target - val;
            int left = 0;
            int right = n - 1;
            bool found = false;
            int mid = 0;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (req == nums[mid]) {
                    found = true;
                    break;
                } else if (req < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (found) {
                if (i < mid) {
                    result.push_back(i+1);
                    result.push_back(mid+1);
                } else {
                    if(i==mid){
                     continue;
                    }else{
                    result.push_back(mid+1);
                    result.push_back(i+1);
                    }
                    
                }
                return result; 
            }
        }
        return result;
    }
};
