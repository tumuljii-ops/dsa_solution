class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {


              unordered_map<int,vector<int>>ans;

              int n=groupSizes.size();

              for(int i=0;i<n;i++){
                 
                    int num=groupSizes[i];
                    ans[num].push_back(i);
              }  

              vector<vector<int>>answer;

              for(auto it:ans){
                 
                    int num=it.first;
                    vector<int>anss=it.second;
                    
                    int n=anss.size()/num;
                    int i=0;

                    while(n>0){
                        vector<int>store;

                        

                        while(i<anss.size()){
                             
                             store.push_back(anss[i]);
                             if(store.size()==num){
                                   i++;
                                   break;
                             }
                             i++;
                        }
                        

                        answer.push_back(store);
                        n--;
                    }

              } 

              return answer;
    }
};