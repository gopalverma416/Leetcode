class Solution {
    private:
    unordered_map<string,bool>mp;
    bool canForm(string word,unordered_set<string>&st){
     if(mp.find(word)!=mp.end()){
        return mp[word];
     }
    int n=word.size();
    for(int i=1;i<=n-1;i++){
        string left=word.substr(0,i);
        string right=word.substr(i);
        if(st.count(left)&& (st.count(right)|| canForm(right,st))){
             mp[word]=true;
             return true;
        }
    }
    return mp[word]=false;
     
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // first approach is hashSwt+dp approach 
       unordered_set<string> st(words.begin(),words.end());
       vector<string>res;
       for(auto word: words){
        if(word.empty()){
         continue;
        }
        st.erase(word);
        if(canForm(word,st)){
        res.push_back(word);
        }
         st.insert(word);
       }
       return res;
    }
};