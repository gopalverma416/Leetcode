#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> St; 

    bool find1(string& temp) {
        return (St.find(temp) != St.end());
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
       
        St = set<string>(bank.begin(), bank.end());

        using P = pair<int, string>;
        queue<P> q; 
        q.push({0, startGene});

        while (!q.empty()) {
            auto [step, temp] = q.front();
            q.pop();

            if (temp == endGene)
                return step;

            int n = temp.size();
            for (int i = 0; i < n; i++) {
                char ch = temp[i];
                for (char c : {'A', 'C', 'G', 'T'}) {
                    temp[i] = c;
                    if (find1(temp)) {
                        St.erase(temp);
                        q.push({step + 1, temp});
                    }
                }
                temp[i] = ch; // restore
            }
        }

        return -1;
    }
};
