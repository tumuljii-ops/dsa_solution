class Solution {
public:
    void combi(int ind,vector<int>& ans,vector<vector<int>>& store,vector<int>&candidates,int target,int sum){
         
            if(sum==target){
                store.push_back(ans);
                return;
            }

            if(ind==candidates.size() || sum>target) return;

            if(sum+candidates[ind]<=target){
                 ans.push_back(candidates[ind]);
                 combi(ind+1,ans,store,candidates,target,sum+candidates[ind]);
                 ans.pop_back();
            }

            int index=ind+1;

            while(index<candidates.size() || candidates[index]==candidates[index-1]){
                //continue;
                index++;
                continue;
                
                }

            combi(index,ans,store,candidates,target,sum);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

           sort(candidates.begin(),candidates.end());
            vector<int>ans;
            vector<vector<int>>store;

            combi(0,ans,store,candidates,target,0);

          

            return store;
    }
};