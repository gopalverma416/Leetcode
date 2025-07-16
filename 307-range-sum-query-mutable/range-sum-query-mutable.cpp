class NumArray {
private:
    vector<int> seg;
    int n;

    void build(vector<int>& nums, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(nums, 2 * idx + 1, low, mid);
        build(nums, 2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateUtil(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            updateUtil(2 * idx + 1, low, mid, i, val);
        else
            updateUtil(2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0; // no overlap
        if (l <= low && high <= r) return seg[idx]; // total overlap

        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateUtil(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};
