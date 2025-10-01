class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        int n=nums.size();
        vector<int>next(n,0);
        vector<int>prevN(n,0);
          if(time==0){  
            vector<int> ans(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }
        int cnt=1;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int val=nums[i];
            if(prev>=val){
                cnt++;
            }else{
                cnt=1;
            }
            prev=val;
            if(cnt>time){
                next[i]=1;
            }
        }
        
        cnt=1;  // reset before backward loop
        prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int val=nums[i];
            if(prev>=val){
                cnt++;
            }else{
                cnt=1;
            }
            prev=val;
            if(cnt>time){
                prevN[i]=1;
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(next[i]==1 && prevN[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
