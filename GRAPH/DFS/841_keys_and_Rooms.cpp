class Solution {
public:

    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int node){

        for(auto it : rooms[node]){

            if(!visited[it]){
                visited[it] = true;
                dfs(rooms, visited, it);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<bool> visited(n, false);

        visited[0] = true;

        dfs(rooms, visited, 0);

        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};