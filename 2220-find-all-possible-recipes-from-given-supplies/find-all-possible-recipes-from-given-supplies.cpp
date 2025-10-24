#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector<vector<string>>& ingredients, 
                                  vector<string>& supplies) {
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;       
        unordered_set<string> supplySet(supplies.begin(), supplies.end()); 
        
        int n = recipes.size();

      
        for (int i = 0; i < n; i++) {
            for (auto& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
            indegree[recipes[i]] = ingredients[i].size();
        }

       
        queue<string> q;
        for (auto& s : supplies) q.push(s);

        vector<string> result;

       
        while (!q.empty()) {
            string item = q.front();
            q.pop();

           
            for (auto& recipe : graph[item]) {
                indegree[recipe]--; 
               
                if (indegree[recipe] == 0) {
                    result.push_back(recipe);
                    q.push(recipe); 
                }
            }
        }

        return result;
    }
};
