class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < players.size() && idx < trainers.size(); ) {
            if (trainers[idx] >= players[i]) {
                cnt++;
                i++;
                idx++;
            } else {
                idx++;
            }
        }
        return cnt;
    }
};
