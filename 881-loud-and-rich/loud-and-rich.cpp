class Solution {
public:
    vector<vector<int>> adj;
    vector<int> quiet;
    vector<int> ans;

    int dfs(int person) {
        if (ans[person] != -1) return ans[person];

        int quietest = person;

        for (int richerPerson : adj[person]) {
            int candidate = dfs(richerPerson);
            if (quiet[candidate] < quiet[quietest]) {
                quietest = candidate;
            }
        }

        return ans[person] = quietest;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quietInput) {
        int n = quietInput.size();
        adj.resize(n);
        quiet = quietInput;
        ans.assign(n, -1);

        for (auto& pair : richer) {
            adj[pair[1]].push_back(pair[0]);
        }

       
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }

        return ans;
    }
};
