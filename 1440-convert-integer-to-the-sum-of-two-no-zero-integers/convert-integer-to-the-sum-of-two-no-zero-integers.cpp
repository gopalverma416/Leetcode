class Solution {
    bool check(int x){
        string temp=to_string(x);
        int n=temp.size();
        for(int i=0;i<n;i++){
            char ch=temp[i];
            if(ch=='0'){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=0;i<n/2+1;i++){
            int val1=i;
            int rem=n-val1;
            if(check(val1) && check(rem)){
                return {val1,rem};
            }
        }
        return {};
    }
};