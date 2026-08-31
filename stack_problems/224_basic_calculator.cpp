class Solution {
public:
    int calculate(string s) {
         
         long long result=0;
         long long num=0;

         long long sign=1;

         stack<long long>st;

         int n=s.length();

         for(int i=0;i<n;i++){
             
               if(isdigit(s[i])){
                 
                   num=num*10+(s[i]-'0');
               }
               else if(s[i]=='+'){
                 
                    result=result+num*sign;
                    num=0;
                    sign=1;
               }
               else if(s[i]=='-'){
                 
                     result=result+num*sign;
                     num=0;
                     sign=-1;
               }
               else if(s[i]=='('){
                 
                     st.push(result);
                     st.push(sign);
                     result=0;
                     sign=1;
               }
               else if(s[i]==')'){
                 
                    result=result+num*sign;

                    long long prev_sign=st.top();
                    st.pop();

                    long long prev_num=st.top();
                    st.pop();

                    result=prev_num+result*prev_sign;
                    num=0;
                    sign=1;


               }
         }

         result=result+num*sign;

         return (int)result;
    }
};
