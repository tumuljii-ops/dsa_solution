class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

               unordered_set<int>ans;
               unordered_set<int>prev;

               for(int x:arr){
                 
                   unordered_set<int>curr;

                   curr.insert(x);

                   for(int num:prev){
                        curr.insert(x|num);
                   }

                   for(int num:curr){
                         ans.insert(num);
                   }

                   prev=move(curr);
               }  

               return ans.size(); 
    }
};