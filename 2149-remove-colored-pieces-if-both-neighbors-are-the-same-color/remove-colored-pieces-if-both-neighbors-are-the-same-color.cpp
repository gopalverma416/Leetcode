class Solution {
public:
    bool winnerOfGame(string nums) {
        int n = nums.size();
        int bob_moves = 0;
        int alice_moves = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] == nums[i + 1] && nums[i - 1] == 'A') {
                if (nums[i] == 'A') {
                    alice_moves++;
                }

            } else {
                if (nums[i - 1] == nums[i + 1] && nums[i-1] == 'B') {
                    if (nums[i] == 'B') {
                        bob_moves++;
                    }
                }
            }
        }
        // yhaa kahi gadbad ho rhi hai bc
        return alice_moves > bob_moves;
    }
};
