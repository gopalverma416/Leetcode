class SORTracker {
public:
    struct cmpMin {  // for minHeap (top k best)
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second < b.second; 
            return a.first > b.first; 
        }
    };
    struct cmpMax {  // for maxHeap (the rest)
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        }
    };

    using P = pair<int,string>;
    priority_queue<P, vector<P>, cmpMin> minHeap; 
    priority_queue<P, vector<P>, cmpMax> maxHeap; 
    int cnt;

    SORTracker() { cnt = 1; }

    void add(string name, int score) {
        P p = {score, name};
        if (!minHeap.empty() && cmpMin()(p, minHeap.top())) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(p);
        } else {
            maxHeap.push(p);
        }
    }

    string get() {
        while (minHeap.size() < cnt) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        string res = minHeap.top().second;
        cnt++;
        return res;
    }
};
