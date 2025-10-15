class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string ram=strs[i];
            sort(ram.begin(),ram.end());
            mp[ram].push_back(strs[i]);
        }
        
         for(auto it: mp){
           result.push_back(it.second);
         }
         return result;
    }
};