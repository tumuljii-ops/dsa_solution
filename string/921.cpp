class Solution {
public:
    int minAddToMakeValid(string s) {
          
          stack<char>st;
          int n=s.length();
          int count=0;

          for(int i=0;i<n;i++){
                 
                 if(s[i]=='('){
                    st.push(s[i]);
                 }
                 else if(s[i]==')' && !st.empty()){
                       st.pop();
                 }
                 else if(s[i]==')' && st.empty()){
                      count++;
                 }
          }

          while(!st.empty()){
               
                count++;
                st.pop();
          }

          return count;
    }
};