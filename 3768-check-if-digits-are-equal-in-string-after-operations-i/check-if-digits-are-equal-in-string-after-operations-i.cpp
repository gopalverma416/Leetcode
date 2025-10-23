class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        if(n==2){
            return s[0]!=s[1]? false:true;
        }
        string ans;
        int sum=0;
        for(int i=1;i<n;i++){
          char ch1=s[i-1];
          char ch2=s[i];
          int idx1=ch1-'0';
          int idx2=ch2-'0';
          sum=(idx1+idx2)%10;
          ans+=(sum+'0');
        }
        int m=ans.size();
        for(int i=1;i<m;i++){
          char ch1=ans[i-1];
          char ch2=ans[i];
          if(ch1!=ch2){
            return hasSameDigits(ans);
          }
        }
        return true;
    }
};