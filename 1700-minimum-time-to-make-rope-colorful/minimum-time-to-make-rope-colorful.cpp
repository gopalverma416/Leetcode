class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int total = 0;
        int prev = 0;  // index of the previous balloon in the current group
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[prev]) {
             
                total += min(neededTime[i], neededTime[prev]);
               
                if (neededTime[i] > neededTime[prev])
                    prev = i;
            } else {
                prev = i;
            }
        }
        return total;
    }
};
