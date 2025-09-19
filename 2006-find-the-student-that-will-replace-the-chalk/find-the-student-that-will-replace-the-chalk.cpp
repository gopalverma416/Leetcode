class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long total=0;
        for(int i=0;i<n;i++){
         total+=chalk[i];
        }
        
         k=k%total;
        if(k==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            int val=chalk[i];
            if(k<val){
                return i;
            }
            k-=val;
        }
        return n-1;
    }
};