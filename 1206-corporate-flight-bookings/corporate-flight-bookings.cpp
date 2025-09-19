class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> ans(n, 0);
        // great approach i got this here
        vector<int> prefix(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seat = bookings[i][2];
            prefix[first - 1] += seat;
            if (last < n) {
                prefix[last] -= seat;
            }
        }
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+prefix[i];
        }
        return prefix;
    }
};