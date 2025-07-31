#include <vector>
#include <set>
#include <numeric>

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
       
        set<int> all_results;
        
        set<int> current_results;
        for (int x : arr) {
          
            set<int> next_results;
            
          
            next_results.insert(x);

            
            for (int prev_or : current_results) {
                next_results.insert(prev_or | x);
            }

            
            current_results = next_results;

            
            for (int res : current_results) {
                all_results.insert(res);
            }
        }

        return all_results.size();
    }
};