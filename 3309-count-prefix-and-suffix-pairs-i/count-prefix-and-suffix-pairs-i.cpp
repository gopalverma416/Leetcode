class Solution {
private:
    bool check(string& nums, string& arr) {
        if (arr.size() < nums.size()) return false; // avoid out-of-range
        int n = arr.size();
        string copy = arr.substr(0, nums.length());               // prefix
        string copy2 = arr.substr(n - nums.length(), nums.length()); // suffix
        return (copy == nums) && (copy2 == nums);
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(); // FIXED typo
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string nums = words[i];
            for (int j = i + 1; j < n; j++) {
                string arr = words[j];
                if (check(nums, arr)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
