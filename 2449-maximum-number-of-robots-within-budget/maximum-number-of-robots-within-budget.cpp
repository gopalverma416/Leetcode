class Solution {
    private:
    bool solve(vector<int>& charge,vector<int>& run,long long budget,int k){
        deque<int>dq;
        long long sum=0;
        int n=charge.size();
        for(int i=0;i<n;i++){
            sum+=run[i];
            while(!dq.empty() && charge[dq.back()]<=charge[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k){
                sum-=run[i-k];
                if(dq.front()==i-k){
                    dq.pop_front();
                }
            }
            if(i>=k-1){
                long long total=charge[dq.front()]+1LL*k*sum;
                if(total<=budget){
                    return true;
                }
            }
    
        }
        return false;

       
    }
public:
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        int low=1;
        int high=n;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(chargeTimes,runningCosts,budget,mid)){
              ans=mid;
              low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};