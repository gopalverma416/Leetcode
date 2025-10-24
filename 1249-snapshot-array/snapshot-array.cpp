#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int,int>>> mp;
    int idx = 0;

    SnapshotArray(int length) {
        mp.resize(length);
        for(int i=0; i<length; i++){
            mp[i].push_back({-1,0}); // initial value
        }
    }

    void set(int index, int val) {
        if(mp[index].back().first == idx){
            mp[index].back().second = val; // overwrite
        } else {
            mp[index].push_back({idx,val}); // add new change
        }
    }

    int snap() {
        return idx++;
    }

    int get(int index, int snap_id) {
        auto &vec = mp[index];
        int l = 0, r = vec.size()-1;
        int ans = 0;
        while(l <= r){
            int m = (l+r)/2;
            if(vec[m].first <= snap_id){
                ans = vec[m].second;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ans;
    }
};
