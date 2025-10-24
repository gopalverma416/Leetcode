class Solution {
private:
    int getPower(int x) {
        int cnt = 0;
        while (x > 1) {
            if (x % 2 == 0) {
                x = x / 2;
                cnt++;
            } else {
                x = 3 * x + 1;
                cnt++;
            }
        }
        return cnt;
    }

public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>> pq;
        for (int i = lo; i <= hi; i++) {
            int power = getPower(i);
            while (pq.size() > k) {
                pq.pop();
            }
            pq.push({power,i});
        }
        while(pq.size()>k){
            pq.pop();
        }
        return pq.top().second;     
    }
};