class Solution {
    private:
    int  find_digit_sum(int n){
        string word=to_string(n);
        int size=word.size();
        int sum=0;
        for(int i=0;i<size;i++){
            int val=(word[i]-'0');
           sum+=val;
        }
        return sum;
    }
public:
   
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>>mp;
        for(int i=1;i<=n;i++){
         int sum_of_group=find_digit_sum(i);
         mp[sum_of_group].push_back(i);
        }
        int maxi=0;
        for(auto it: mp){
            int m=it.second.size();
            maxi=max(maxi,m);
        }
        int cnt=0;
         for(auto it: mp){
            int m=it.second.size();
            if(m==maxi){
            cnt++;
            }
        }
        return cnt;

    }
};