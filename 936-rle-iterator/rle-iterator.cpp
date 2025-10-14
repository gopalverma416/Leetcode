class RLEIterator {
public:
    int idx = 0;
    vector<int> arr;
    int size;

    RLEIterator(vector<int>& encoding) {
        arr = encoding;
        size = encoding.size();
    }

    int next(int n) {
        while (idx < size) {
            if (arr[idx] >= n) {
                arr[idx] -= n;
                return arr[idx + 1];
            } else {
                n -= arr[idx];
                idx += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
