class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> secretFreq(10, 0); // for unmatched digits
        vector<int> guessFreq(10, 0);

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secretFreq[secret[i] - '0']++;
                guessFreq[guess[i] - '0']++;
            }
        }

        int cows = 0;
        for (int d = 0; d < 10; d++) {
            cows += min(secretFreq[d], guessFreq[d]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
