class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mp; // stores frequency of numbers in current window
        int left = 0;

        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;

            // when window size exceeds k, shrink from left
            if (right - left + 1 > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }

            // when window is exactly size k
            if (right - left + 1 == k) {
               
                vector<pair<int, int>> freq(mp.begin(), mp.end());
                
               
                sort(freq.begin(), freq.end(), [&](auto &a, auto &b) {
                    if (a.second == b.second)
                        return a.first > b.first;
                    return a.second > b.second;
                });

                int sum = 0;
                int count = 0;
                for (auto &[num, f] : freq) {
                    sum += num * f;
                    count++;
                    if (count == x) break;
                }

                result.push_back(sum);
            }
        }
        return result;
    }
};
