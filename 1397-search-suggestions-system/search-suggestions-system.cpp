struct TrieNode{
    TrieNode* children[26]={nullptr};
    vector<string>suggestion;
};

class Solution {
public:
     TrieNode* root;
     Solution(){
        root=new TrieNode();
     }
     void insert(string& word){
        TrieNode* node=root;
        for(auto c: word){
            int idx=c-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
            if(node->suggestion.size()<3){
                node->suggestion.push_back(word);
            }
        }
     }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>res;
        for(auto& p: products){
            insert(p);
        }
        TrieNode* node=root;
       for(char& ch:searchWord){
        if(node){
         node=node->children[ch-'a'];
        }
        if(node){
            res.push_back(node->suggestion);
        }else{
            res.push_back({});
        }
       }
       return res;

    }
};