class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp1, mp2;
        for(auto x: basket1) mp1[x]++;
        for(auto y: basket2) mp2[y]++;
        
        for(auto x: basket1) {
            if((mp1[x] + mp2[x]) % 2 != 0) return -1;
        }
        for(auto y: basket2) {
            if((mp1[y] + mp2[y]) % 2 != 0) return -1;
        }

        int mini = INT_MAX;
        unordered_map<int,bool>check;
        vector<int> aadu1, aadu2;

        for(auto& [x, c1] : mp1) {
            int c2 = mp2[x];
            int diff = c1 - c2;
            mini = min(mini, x);
            if(diff > 0) {
                for(int i = 0; i < diff / 2; i++) aadu1.push_back(x);
            }
            else if(diff < 0) {
                for(int i = 0; i < -diff / 2; i++) aadu2.push_back(x);
            }
        }

        

        sort(aadu1.begin(), aadu1.end());
        sort(aadu2.begin(), aadu2.end(), greater<int>()); 

        long long score = 0;
        for(int i = 0; i < aadu1.size(); i++) {
            score += min({aadu1[i], aadu2[i], 2 * mini});
        }

        return score;
    }
};
