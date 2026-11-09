class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
            
             int n=heights.size();
             int i=0;
             priority_queue<int>pq;

             for(;i<n-1;i++){
                  
                   if(heights[i]>=heights[i+1]){
                        continue;
                   }

                   int diff=abs(heights[i]-heights[i+1]);

                   if(diff<=bricks){
                       bricks-=diff;
                       pq.push(diff);
                   }
                   else if(ladders>0){

                       if(!pq.empty() && pq.top()>diff){
                           
                           int x=pq.top();
                           pq.pop();

                           bricks+=(x-diff);
                           pq.push(diff);
                       }
                       
                       ladders--;
                   }
                   else{
                    break;
                   }

             }

             return i;
    }
};