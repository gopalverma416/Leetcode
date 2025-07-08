class Solution {
public:
    int stoneGameVI(vector<int>& arr, vector<int>& nums) {
      priority_queue<pair<int,int>>pq;
      int n=arr.size();
      for(int i=0;i<n;i++){
        int total=arr[i]+nums[i];
        pq.emplace(total,i);
      }
      bool turn=true;
      int Atotal=0;
      int Btotal=0;
      while(!pq.empty()){
        auto [sum,idx]=pq.top();
        pq.pop();
        if(turn){
        Atotal+=arr[idx];
        turn=false;
        }else{
            Btotal+=nums[idx];
            turn=true;
        }

      }
      if(Atotal>Btotal){
        return 1;
      }else if(Btotal>Atotal){
        return -1;
      }else{
        return 0;
      }
    }
};