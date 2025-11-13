class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int j=0;
        int i=0;
        while(j<m){
          if(s[i]==t[j]){
            i++;
          }
          j++;
        }
        if(i==n){
            return true;
        }
        return false;
    }
};