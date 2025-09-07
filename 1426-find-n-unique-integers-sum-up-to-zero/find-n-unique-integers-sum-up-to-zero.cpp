class Solution {
public:
    vector<int> sumZero(int n) {
        int mid = n / 2;
        vector<int> ans;
        for (int i = mid; i > 0; i--) {
            int val = i;
            ans.push_back(-val);
        }
        if(n%2!=0){
            ans.push_back(0);
        }
        for(int i=1;i<=mid;i++){
            ans.push_back(i);
        }
        return ans;
    }
};