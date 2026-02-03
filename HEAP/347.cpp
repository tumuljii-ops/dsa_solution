class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
         unordered_map<int,int>mpp;

         for(int i=0;i<nums.size();i++){
             mpp[nums[i]]++;
         }

         priority_queue<pair<int,int>>pq;

         for(auto it:mpp){
               int num1=it.first;
               int num2=it.second;
               pq.push({num2,num1});
         }

         vector<int>ans;

         while(k>0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
         }


      return ans;


     }
};