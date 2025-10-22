class Solution {
public:
   string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> diff(n + 1, 0);

   
    for (auto &shift : shifts) {
        int start = shift[0], end = shift[1];
        int val = (shift[2] == 1) ? 1 : -1;
        diff[start] += val;
        if (end + 1 < n) diff[end + 1] -= val;
    }

   
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }

    
    for (int i = 0; i < n; i++) {
        int shift_val = diff[i] % 26;   
        if (shift_val < 0) shift_val += 26; 
        s[i] = 'a' + (s[i] - 'a' + shift_val) % 26;
    }

    return s;
}

};