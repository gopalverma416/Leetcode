class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                cnt++;
            }else if(ch==')' && cnt<=0){
               ans++;
            }else if(ch==')' && cnt>0) {
                cnt--;
            }
        }
         if(cnt>0){
            return cnt+ans;
         }
         return ans;
    }
};