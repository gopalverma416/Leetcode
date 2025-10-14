class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       vector<vector<int>>sub(26);
       for(int i=0;i<s.size();i++){
        sub[s[i]-'a'].push_back(i);
       }
       int cnt=0;
      for(auto word:words){
        int prev=-1;
        bool ok=true;
        for(auto c:word){
            auto& position=sub[c-'a'];
            auto it=upper_bound(position.begin(),position.end(),prev);
            if(it==position.end()){
                ok=false;
                break;
            }
            prev=*it;
        }
        if(ok){
            cnt++;
        }
      }
      return cnt;
    }
};