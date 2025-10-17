class Solution {
public:
       using pii = pair<int,string>;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
         priority_queue<pii,vector<pii>,greater<pii>>pq;
         unordered_set st(wordList.begin(),wordList.end());
         pq.push({1,beginWord});
         
         while(!pq.empty()){
            auto [step,word]=pq.top();
            pq.pop();
            if(word==endWord){
                return step;
            }
            int n=word.size();
            for(int i=0;i<n;i++){
                char ch=word[i];
                char original=ch;
                for(int j=0;j<26;j++){
                 word[i]='a'+j;
                 if(st.find(word)!=st.end()){
                    pq.push({step+1,word});
                    st.erase(word);
                 }
                }
                word[i]=original;
            }
         }
         return 0;
    }
};