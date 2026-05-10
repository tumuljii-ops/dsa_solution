class Solution {
public:
    int minMoves2(vector<int>& nums) {
            
             int n=nums.size();

             int median;
              
             median=n/2;

             sort(nums.begin(),nums.end());

             int total=0;

             for(int i=0;i<n;i++){
                  total+=abs(nums[i]-nums[median]);
             }


             return total;
             
           
    }
};