class Solution {
public:

    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if(a.first == b.first)
                return a.second > b.second;   
            return a.first > b.first;         
        }
    };

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(int i = 0; i < arr.size(); i++){
            int dist = abs(arr[i] - x);
            pq.push({dist, arr[i]});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end()); 
        return ans;
    }
};
