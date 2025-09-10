class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = friendships.size();
        unordered_set<int> sad;

        
        for (int i = 0; i < m; i++) {
            int u = friendships[i][0] - 1;
            int v = friendships[i][1] - 1;

            unordered_set<int> st(languages[u].begin(), languages[u].end());
            bool isHappy = false;
            for (auto& lang : languages[v]) {
                if (st.find(lang) != st.end()) {
                    isHappy = true;
                    break;
                }
            }
            if (!isHappy) {
                sad.insert(u);
                sad.insert(v);
            }
        }

        if (sad.empty()) return 0; 

       
        vector<int> langCount(n + 1, 0);
        for (auto person : sad) {
            for (auto lang : languages[person]) {
                langCount[lang]++;
            }
        }

     
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            maxi = max(maxi, langCount[i]);
        }

    
        return sad.size() - maxi;
    }
};
