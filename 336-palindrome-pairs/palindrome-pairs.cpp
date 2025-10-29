class Solution {
private:
    bool isPalindrome(const string &s, int l, int r) {     
        while (l < r) {                                  
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> res;
        int n = words.size();

      
        for (int i = 0; i < n; ++i) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

       
        for (int i = 0; i < n; ++i) {
            string w = words[i];
            int len = w.size();

            for (int cut = 0; cut <= len; ++cut) {      
                string left = w.substr(0, cut);           
                string right = w.substr(cut);           

              
                if (isPalindrome(w, 0, cut - 1)) {
                    if (mp.count(right) && mp[right] != i)
                        res.push_back({mp[right], i});    
                }

              
                if (cut != len && isPalindrome(w, cut, len - 1)) {
                    if (mp.count(left) && mp[left] != i)
                        res.push_back({i, mp[left]});    
                }
            }
        }
        return res;
    }
};
