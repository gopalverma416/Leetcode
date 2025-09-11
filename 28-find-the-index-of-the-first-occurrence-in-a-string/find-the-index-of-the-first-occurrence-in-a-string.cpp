class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        for (int i = 0; i < n; i++) {
            int j = 0;
            while ( j< needle.size() &&  needle[j] == haystack[i+j] ) {
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
     
        }
        return -1;
    }
};