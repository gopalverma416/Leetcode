class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int gift : gifts) {
            pq.push(gift);
        }

        while (k--) {
            int val = pq.top();
            pq.pop();
            int reduced = floor(sqrt(val));
            pq.push(reduced);
        }

        long long cnt = 0;
        while (!pq.empty()) {
            cnt += pq.top();
            pq.pop();
        }

        return cnt;
    }
};
