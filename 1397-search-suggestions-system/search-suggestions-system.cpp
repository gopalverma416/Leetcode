class TrieNode {
    public:
    TrieNode* children[26];
    vector<string> suggestion;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Solution {
    public:
    TrieNode* root;
    Solution() { root = new TrieNode(); }
    void insert(string& word) {
        TrieNode* node = root;
        for (auto ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
            if (node->suggestion.size() < 3) {
                node->suggestion.push_back(word);
            }
        }
    }


    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        int n = products.size();
          sort(products.begin(), products.end());
        for (int i = 0; i < n; i++) {
            string ans = products[i];
            insert(ans);
        }
        TrieNode* curr = root;
        int m = searchWord.size();
        vector<vector<string>> result;
        for (int i = 0; i < m; i++) {
            char ch = searchWord[i];
            int val = ch - 'a';
             if (curr)
                curr = curr->children[val];
            
            // ✅ MINOR FIX #2 — if curr is nullptr, push empty vector
            if (curr)
                result.push_back(curr->suggestion);
            else
                result.push_back({});
        }
        return result;
    }
};