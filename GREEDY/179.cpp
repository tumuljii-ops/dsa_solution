class Solution {
public:
    string largestNumber(vector<int>& nums) {

             int n=nums.size();

             map<int,vector<int>,greater<int>>mpp1;

             for(int i=0;i<nums.size();i++){
                  
                    int x=nums[i];

                    while(x>9){
                         x=x/10;
                    }

                    mpp1[x].push_back(nums[i]);
             }

             string answer="";

             for(auto it:mpp1){
                  
                  vector<int>ans=it.second;

                  sort(ans.begin(),ans.end(),[](int a,int b){
                      
                       return to_string(a)+to_string(b)>to_string(b)+to_string(a);
                  });

                  for(int i=0;i<ans.size();i++){
                        answer=answer+to_string(ans[i]);
                  }
             }

             if(!answer.empty() && answer[0]=='0'){
                    return "0";
             }

            return answer;    
    }
};