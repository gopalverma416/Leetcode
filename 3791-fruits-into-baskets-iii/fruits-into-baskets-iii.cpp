class Solution {
private:
    // Build the Segment Tree
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& segment) {
        if (l == r) {
            segment[i] = baskets[l]; // FIXED
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, baskets, segment);
        build(2 * i + 2, mid + 1, r, baskets, segment);
        segment[i] = max(segment[2 * i + 1], segment[2 * i + 2]);
    }

    // Query to place the fruit in a basket
    bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int fruit) {
        if (segmentTree[i] < fruit) return false;

        if (l == r) {
            segmentTree[i] = -1; // Mark as used
            return true;
        }

        int mid = l + (r - l) / 2;
        bool placed = querySegmentTree(2 * i + 1, l, mid, segmentTree, fruit);
        if (!placed) {
            placed = querySegmentTree(2 * i + 2, mid + 1, r, segmentTree, fruit);
        }

        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        return placed;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segment(4 * n, -1);
        build(0, 0, n - 1, baskets, segment);

        int m = fruits.size();
        int unplaced = 0;

        for (int i = 0; i < m; ++i) {
            bool placed = querySegmentTree(0, 0, n - 1, segment, fruits[i]);
            if (!placed) unplaced++;
        }

        return unplaced;
    }
};
