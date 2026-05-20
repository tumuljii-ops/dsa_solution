class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
             
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        vector<int> st = intervals[0];  

        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= st[1]){
                if(intervals[i][1] > st[1]){
                    st[1] = intervals[i][1];
                }
            }
            else{
                ans.push_back(st);
                st = intervals[i];
            }
        }

        ans.push_back(st);

        return ans;
    }
};
