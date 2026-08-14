class NestedIterator {
public:
    stack<NestedInteger>st;
    NestedIterator(vector<NestedInteger> &nestedList) {
         
         for(int i=nestedList.size()-1;i>=0;i--){
               st.push(nestedList[i]);
         }
    }
    
    int next() {
         
          int result=st.top().getInteger();
          st.pop();

          return result;
    }
    
    bool hasNext() {
        while(!st.empty()){

             NestedInteger curr=st.top();

             if(curr.isInteger()){
                 return true;
             }

             st.pop();

            const vector<NestedInteger>&list=curr.getList();
             for (int i = list.size() - 1; i >= 0; i--) {
                st.push(list[i]);
            }
        }

        return false;
    }
};