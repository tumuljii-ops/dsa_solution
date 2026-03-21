class Solution {
public:
    void perm(vector<int>&nums,vector<bool>&visited,vector<int>&path,vector<vector<int>>&store){
             if(path.size()==nums.size()){
                store.push_back(path);
                return;
             }

             for(int i=0;i<nums.size();i++){
                  if(visited[i]==true) continue;

                  if(i>0 && nums[i]==nums[i-1] && visited[i-1]==false) continue;
                  
                  path.push_back(nums[i]);
                  visited[i]=true;

                  perm(nums,visited,path,store);
                  path.pop_back();
                  visited[i]=false;

             }
              
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         
         sort(nums.begin(),nums.end());
         int n=nums.size();
         vector<bool>visited(n,false);
         vector<int>path;
         vector<vector<int>>store;

         perm(nums,visited,path,store);

         return store;
    }
};