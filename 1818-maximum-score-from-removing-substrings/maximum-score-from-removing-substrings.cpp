class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        
       
        char first1, first2;
        int firstVal, secondVal;
        
        if (x > y) {
            first1 = 'a'; first2 = 'b'; firstVal = x; secondVal = y;
        } else {
            first1 = 'b'; first2 = 'a'; firstVal = y; secondVal = x;
        }

       
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && st.top() == first1 && ch == first2) {
                st.pop();
                score += firstVal;
            } else {
                st.push(ch);
            }
        }

      
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char ch : remaining) {
            if (!st.empty() && st.top() == first2 && ch == first1) {
                st.pop();
                score += secondVal;
            } else {
                st.push(ch);
            }
        }

        return score;
    }
};
