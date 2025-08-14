class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<char, int> mp;
        int n = num.size();
        mp[num[0]]++;
        mp[num[1]]++;
        int left = 0;
        int result = -1; 

        for (int i = 2; i < n; i++) {
            char val = num[i];
            mp[val]++;

           
            if (mp.size() == 1) {
                string kar = num.substr(left, 3);
                int anshu = stoi(kar);
                result = max(result, anshu);
            }

           
            mp[num[left]]--;
            if (mp[num[left]] == 0) mp.erase(num[left]);
            left++;
        }

       
        if (result == -1) return "";
        
        
        string ans = to_string(result);
        while (ans.size() < 3) ans = "0" + ans;
        return ans;
    }
};
