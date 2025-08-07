class Solution {
    private:
    void solve(int rem,int count,string& result,vector<string>& prem){
        if(count==0 && rem==0){
            prem.push_back(result);
            return;
        }
        if(rem>0 ){
            string copy=result+'(';
            solve(rem-1,count+1,copy,prem);
        }
        if(count>0){
            string ramu=result+')';
            solve(rem,count-1,ramu,prem);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string result;
        int count=0;
        int rem=n;
        vector<string> prem;
        solve(rem,count,result,prem);
         return prem;
    }
};