class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>arr(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            int val=ch-'a';
            arr[val]++;
        }
        int m=t.size();
        for(int i=0;i<m;i++){
           char ch=t[i];
           int val=t[i]-'a';
           arr[val]--;
           if(arr[val]<0){
            return ch;
           }
        }
        return 'a';
    }
};