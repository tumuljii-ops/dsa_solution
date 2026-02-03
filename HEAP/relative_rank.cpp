class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }

        vector<string> ans(score.size());
        int rank = 1;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(rank == 1)
                ans[top.second] = "Gold Medal";
            else if(rank == 2)
                ans[top.second] = "Silver Medal";
            else if(rank == 3)
                ans[top.second] = "Bronze Medal";
            else
                ans[top.second] = to_string(rank);

            rank++;
        }

        return ans;
    }
};
