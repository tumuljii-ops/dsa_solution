class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        queue<pair<int,int>> q; // {number, operations}
        q.push({x,0});

        vector<int> visited(100001,false);
        visited[x] = true;

        while(!q.empty()){

            int num = q.front().first;
            int count = q.front().second;
            q.pop();

            if(num == y){
                return count;
            }

            if(num % 11 == 0){

                int next = num / 11;

                if(next >= 0 && !visited[next]){
                    visited[next] = true;
                    q.push({next,count+1});
                }
            }

            if(num % 5 == 0){

                int next = num / 5;

                if(next >= 0 && !visited[next]){
                    visited[next] = true;
                    q.push({next,count+1});
                }
            }

            int next = num + 1;

            if(next <= 100000 && !visited[next]){
                visited[next] = true;
                q.push({next,count+1});
            }

            next = num - 1;

            if(next >= 0 && !visited[next]){
                visited[next] = true;
                q.push({next,count+1});
            }
        }

        return -1;
    }
};