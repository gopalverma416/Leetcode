class Solution {
    private:
    string addToOdd(string s, int a) {
    // Add 'a' to all odd indices
    for (int i = 1; i < s.size(); i += 2) {
        s[i] = ((s[i] - '0' + a) % 10) + '0';
    }
    return s;
}

public:
    string findLexSmallestString(string s, int a, int b) {
          set<string> visited; // To avoid revisiting
    queue<string> q; // For BFS
    string res = s; // Store the smallest string
    q.push(s); // Start with initial string
    visited.insert(s); // Mark as visited
    while (!q.empty()) { // While there are strings to process
        string curr = q.front(); q.pop(); // Get next string
        if (curr < res) res = curr; // Update result if smaller
        // Operation 1: Add to odd indices
        string addStr = addToOdd(curr, a); // Add 'a' to odd indices
        if (!visited.count(addStr)) { // If not visited
            visited.insert(addStr); // Mark as visited
            q.push(addStr); // Add to queue
        }
        // Operation 2: Rotate
        string rotStr = curr.substr(b) + curr.substr(0, b); // Rotate by b
        if (!visited.count(rotStr)) { // If not visited
            visited.insert(rotStr); // Mark as visited
            q.push(rotStr); // Add to queue
        }
    }
    return res; // Return the smallest string fou
    }
};