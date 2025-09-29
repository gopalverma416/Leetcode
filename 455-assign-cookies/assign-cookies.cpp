class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int idx1=0;
        int idx2=0;
        int cnt=0;
        while(idx1<n && idx2<m){
        if(g[idx1]<=s[idx2]){
            idx1++;
            idx2++;
            cnt++;
        }else if(g[idx1]>s[idx2]){
            idx2++;
        }
        }
        return cnt;
    }
};