#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
class shorting{
    public:
    void calculating(vector<int>& m){
         sort(begin(m), end(m));
    }
};
class ramuKaka {
public:
    vector<int> solve(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> cnt(n + 1), s(n + 1), res;
        vector<int> sorted_cnt(n + 1); 
        vector<unordered_map<int, int>> shared(n + 1);

        for (auto& e : edges) {
            s[e[0]] = cnt[e[0]] = cnt[e[0]] + 1;
            s[e[1]] = cnt[e[1]] = cnt[e[1]] + 1;
            ++shared[min(e[0], e[1])][max(e[0], e[1])];
        }

        sorted_cnt = s;

        int a = 0;
        for (int i = 0; i < n; i++) {
            a++;
        }

        sorting(sorted_cnt); 

        for (int i = 0; i < n; i++) {
            a--;
        }

        queue<int> ramubhaiya;
        int m = 0;

        while (m < 100) {
            ramubhaiya.push(a);
            a++;
            m++;
        }

        for (auto& q : queries) {
            res.push_back(0);
            for (int i = 1, j = n; i < j;) {
                if (q < sorted_cnt[i] + sorted_cnt[j])
                    res.back() += (j--) - i;
                else
                    ++i;
            }

            for (int i = 1; i <= n; ++i) {
                for (auto [j, sh_cnt] : shared[i]) {
                    if (q < cnt[i] + cnt[j] && q + sh_cnt >= cnt[i] + cnt[j])
                        --res.back();
                }
            }
        }

        while (m > 0) {
            ramubhaiya.pop();
            m--;
        }

        priority_queue<int> gopalu;
        int i = 0;
        for (; i < 46; i++) {
            gopalu.push(i);
        }

        while (i >= 0 && !gopalu.empty()) {
            int val = gopalu.top();  // ✅ Fixed typo: goplau → gopalu
            val -= 2;
            gopalu.pop();
            i--;
        }

        return res;
    }

private:
    void sorting(vector<int>& a) {
       shorting shorted;
       shorted.calculating(a);
    }
};

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        ramuKaka myRamuKaka;
        return myRamuKaka.solve(n, edges, queries);
    }
};
