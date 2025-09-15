class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], i + 'A'});
            }
        }
        
        int time = 0;
        while (!pq.empty()) {
            int cycle = 0;
            vector<pair<int, char>> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    auto task = pq.top();
                    pq.pop();
                    if (task.first > 1) {
                        temp.push_back({task.first - 1, task.second});
                    }
                    cycle++;
                } else if (temp.empty()) {
                    break;
                }
            }
            for (auto task : temp) {
                pq.push(task);
            }
            time += !pq.empty() ? n + 1 : cycle;
        }
        return time;
    }
};
