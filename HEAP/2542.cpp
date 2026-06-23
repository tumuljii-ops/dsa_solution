class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        vector<pair<int,int>> vec;

        for(int i = 0; i < n; i++) {
            vec.push_back({nums2[i], nums1[i]});
        }

        sort(vec.rbegin(), vec.rend());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++) {

            sum += vec[i].second;
            pq.push(vec[i].second);

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) {
                ans = max(ans, sum * 1LL * vec[i].first);
            }
        }

        return ans;
    }
};