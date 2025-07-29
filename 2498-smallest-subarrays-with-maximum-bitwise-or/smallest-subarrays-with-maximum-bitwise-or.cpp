class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> setIndex(32,-1);
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            int val=nums[i];
            int minIdx=i;
            for(int j=0;j<32;j++){
                if(!(val & (1<<j))){
                  if(setIndex[j]!=-1){
                    minIdx=max(minIdx,setIndex[j]);
                  }
                }else{
                    setIndex[j]=i;
                }
            }
            int a=minIdx-i+1;
            ans[i]=a;
        }
        return ans;
    }
};