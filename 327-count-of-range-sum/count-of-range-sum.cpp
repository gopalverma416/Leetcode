#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int n) : n(n) {
        tree.assign(4 * n, 0);
    }

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            tree[idx]++;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * idx, l, mid, pos);
        else update(2 * idx + 1, mid + 1, r, pos);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) +
               query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Coordinate compression
        vector<long long> allVals = prefix;
        for (auto p : prefix) {
            allVals.push_back(p - lower);
            allVals.push_back(p - upper);
        }
        sort(allVals.begin(), allVals.end());
        allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

        auto getIndex = [&](long long val) {
            return (int)(lower_bound(allVals.begin(), allVals.end(), val) - allVals.begin());
        };

        SegmentTree st(allVals.size());
        int count = 0;

        // Insert prefix[0] into segment tree
        st.update(1, 0, allVals.size() - 1, getIndex(prefix[0]));

        for (int i = 1; i <= n; i++) {
            long long leftVal = prefix[i] - upper;
            long long rightVal = prefix[i] - lower;
            int leftIdx = getIndex(leftVal);
            int rightIdx = getIndex(rightVal);
            count += st.query(1, 0, allVals.size() - 1, leftIdx, rightIdx);
            st.update(1, 0, allVals.size() - 1, getIndex(prefix[i]));
        }
        return count;
    }
};
