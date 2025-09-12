class Solution {
public:
    bool doesAliceWin(string s) {
       int cnt=0;
       int n=s.size();
       for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch=='a'|| ch=='e'|| ch=='i'||ch=='o'||ch=='u'){
            cnt++;
        }
       }
       if(cnt==0){
        return false;
       }
        return true;
    }
};