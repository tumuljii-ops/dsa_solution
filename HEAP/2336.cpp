class SmallestInfiniteSet {
public:
   priority_queue<int,vector<int>,greater<int>>pq;
   unordered_set<int>st;
   int carry;

    SmallestInfiniteSet() {
        carry=1;
    }
    
    int popSmallest() {
        
        if(!pq.empty()){
             int a=pq.top();
             pq.pop();

             st.erase(a);


             return a;
        }

        return carry++;
    }
    
    void addBack(int num) {
         
          if(carry>=num){
             return ;
          }

          if(st.find(num)!=st.end()){
              return ;
          }

          pq.push(num);
          st.insert(num);
    }
};

