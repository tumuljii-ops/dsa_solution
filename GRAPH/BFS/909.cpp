class Solution {
public:

    pair<int,int> getCoordinates(int square, int n){

        int rowFromBottom = (square - 1) / n;

        int row = n - 1 - rowFromBottom;

        int col = (square - 1) % n;

        if(rowFromBottom % 2 == 1)
            col = n - 1 - col;

        return {row,col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        vector<int> dist(n*n+1,-1);

        queue<int> q;

        q.push(1);

        dist[1]=0;

        while(!q.empty()){

            int curr=q.front();

            q.pop();

            if(curr==n*n)
                return dist[curr];

            for(int next=curr+1;next<=min(curr+6,n*n);next++){

                auto [r,c]=getCoordinates(next,n);

                int destination=next;

                if(board[r][c]!=-1)
                    destination=board[r][c];

                if(dist[destination]==-1){

                    dist[destination]=dist[curr]+1;

                    q.push(destination);
                }
            }
        }

        return -1;
    }
};