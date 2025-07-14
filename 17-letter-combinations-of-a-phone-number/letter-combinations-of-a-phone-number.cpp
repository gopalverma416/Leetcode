class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string path;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(path);
                return;
            }

            string letters = mapping[digits[index] - '0'];
            for (char ch : letters) {
                path.push_back(ch);        
                backtrack(index + 1);       
                path.pop_back();            
            }
        };

        backtrack(0);
        return result;
    }
};
