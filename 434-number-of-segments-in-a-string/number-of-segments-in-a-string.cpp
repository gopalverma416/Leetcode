class Solution {
public:
    int countSegments(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch==' '){
                continue;
            }
            int j=i;
            while(j<n && s[j]!=' '){
                j++;
            }
            count++;
            i=j;
        }
        return count; 
    }
};