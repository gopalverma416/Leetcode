class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [a,b] = q.front(); q.pop();
            if (a == target || b == target || a+b == target) return true;
            if(visited.count({a,b})) continue;
            visited.insert({a,b});
        
            q.push({x,b});
          
            q.push({a,y});
          
            q.push({0,b});
      
            q.push({a,0});
       
            int pour = min(a, y-b);
            q.push({a-pour, b+pour});
          
            pour = min(b, x-a);
            q.push({a+pour, b-pour});
        }
        return false;
    }
};
