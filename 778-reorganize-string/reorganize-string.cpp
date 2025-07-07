class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        for (char ch : s) {
            mp[ch]++;
            if (mp[ch] > (n + 1) / 2) return "";  
        }

       
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, freq] : mp) {
            pq.push({freq, ch});
        }

        string ans = "";
        while (pq.size() >= 2) {
            auto [freq1, ch1] = pq.top(); pq.pop();
            auto [freq2, ch2] = pq.top(); pq.pop();

            ans += ch1;
            ans += ch2;

            if (--freq1 > 0) pq.push({freq1, ch1});
            if (--freq2 > 0) pq.push({freq2, ch2});
        }

        if (!pq.empty()) {
            if (pq.top().first > 1) return "";  
            ans += pq.top().second;
        }

        return ans;
    }
};
