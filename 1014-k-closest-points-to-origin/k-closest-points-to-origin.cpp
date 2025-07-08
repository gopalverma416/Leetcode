class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        for(int i=0;i<points.size();i++){
            int x_cord=points[i][0];
            int y_cord=points[i][1];
            int x_square=(x_cord*x_cord);
            int y_square=(y_cord*y_cord);
            int total=x_square+y_square;
            double ans=sqrt(total);
            pq.emplace(ans,i);
        }
        vector<vector<int>>ans;
        while(!pq.empty() && ans.size()<k){
            auto [sum,idx]=pq.top();
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;

    }
};