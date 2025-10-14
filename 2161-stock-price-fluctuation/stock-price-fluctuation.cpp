

class StockPrice {
private:
    unordered_map<int, int> timePrice; 
   priority_queue<std::pair<int,int>> maxHeap; 
    priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> minHeap; 
    int latestTime;

public:
    StockPrice() {
        latestTime = 0;
    }

    void update(int timestamp, int price) {
        timePrice[timestamp] = price;
        latestTime = std::max(latestTime, timestamp);
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }

    int current() {
        return timePrice[latestTime];
    }

    int maximum() {
        while (true) {
            auto [price, time] = maxHeap.top();
            if (timePrice[time] == price) return price; // valid max
            maxHeap.pop(); // outdated, remove
        }
    }

    int minimum() {
        while (true) {
            auto [price, time] = minHeap.top();
            if (timePrice[time] == price) return price; // valid min
            minHeap.pop(); // outdated, remove
        }
    }
};
