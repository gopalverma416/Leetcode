#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    struct Packet {
        int src, dst, time;
    };

    int capacity;
    deque<Packet> dq;
    unordered_map<int, vector<int>> destTimes; // destination -> sorted timestamps
    unordered_map<int, int> destPtr; // pointer to first valid timestamp in vector
    set<tuple<int,int,int>> packetSet; // to avoid duplicates

    Router(int memoryLimit) {
        capacity = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> key = {source,destination,timestamp};
        if(packetSet.count(key)) return false;

        Packet p = {source,destination,timestamp};
        dq.push_back(p);
        destTimes[destination].push_back(timestamp);
        packetSet.insert(key);

        while(dq.size() > capacity){
            Packet old = dq.front();
            dq.pop_front();
            destPtr[old.dst]++; // just move the pointer
            packetSet.erase({old.src, old.dst, old.time});
        }

        return true;
    }

    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        Packet p = dq.front();
        dq.pop_front();
        destPtr[p.dst]++;
        packetSet.erase({p.src, p.dst, p.time});
        return {p.src, p.dst, p.time};
    }

    int getCount(int destination, int startTime, int endTime) {
        if(destTimes.find(destination) == destTimes.end()) return 0;
        auto &vec = destTimes[destination];
        int startIdx = lower_bound(vec.begin() + destPtr[destination], vec.end(), startTime) - vec.begin();
        int endIdx = upper_bound(vec.begin() + destPtr[destination], vec.end(), endTime) - vec.begin();
        return endIdx - startIdx;
    }
};
