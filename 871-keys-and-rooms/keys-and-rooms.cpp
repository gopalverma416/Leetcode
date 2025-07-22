class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0, rooms, vis);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
       return true;
    }
    private:
    void dfs(int room ,vector<vector<int>>& rooms,vector<bool>& vis){
        vis[room]=true;
        for(auto it: rooms[room]){
            if(vis[it]==false){
                dfs(it,rooms,vis);
            }
        }
    }
};