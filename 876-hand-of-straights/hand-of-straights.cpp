class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if (n % k != 0) return false; // must divide evenly

        map<int,int> mp;
        for (int val : hand) {
            mp[val]++;
        }

        while (!mp.empty()) {
            int first = mp.begin()->first;
            
            for (int i = 0; i < k; i++) {
                int card = first + i;
                if (mp.find(card) == mp.end()) {
                    return false; 
                }
                mp[card]--;
                if (mp[card] == 0) {
                    mp.erase(card);
                }
            }
        }
        return true;
    }
};
