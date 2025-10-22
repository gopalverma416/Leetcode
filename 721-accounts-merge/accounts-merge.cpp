
class Solution {
    unordered_map<string, string> parent;  
    unordered_map<string, int> size;      

    
    string find(const string& s) {
        if (parent[s] != s) 
            parent[s] = find(parent[s]);
        return parent[s];
    }

    
    void unionEmails(const string& a, const string& b) {
        string pa = find(a);
        string pb = find(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) {
            parent[pa] = pb;
            size[pb] += size[pa];
        } else {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // Initialize DSU and merge emails in the same account
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (!parent.count(email)) {
                    parent[email] = email;
                    size[email] = 1;
                }
                emailToName[email] = name;
                unionEmails(account[1], email);  // merge all emails in this account
            }
        }

        // Group emails by root parent
        unordered_map<string, vector<string>> groups;
        for (auto& [email, _] : parent) {
            string root = find(email);
            groups[root].push_back(email);
        }

        // Build result
        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(emailToName[root]); // name
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }

        return result;
    }
};