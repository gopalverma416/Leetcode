class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx, int n, int k, vector<int>& res) {
         if(res.size()==k){
            if(n==0){
                result.push_back(res);
            }
            return;
         }
        for (int i = idx; i <= 9; i++) {
            if (i > n) {
                continue;
            }
            res.push_back(i);
            solve(i+1, n-i, k , res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        solve(1, n, k, res);
       
        return result;
    }
};