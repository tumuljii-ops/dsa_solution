class Solution {
public:
    int calculate(string s) {
           
           long long result=0;
           long long sign=1;
           int n=s.length();
           stack<long long>st;

           long long number=0;

           for(char ch:s){
             
                if(isdigit(ch)){
                    number=number*10+(ch-'0');

                }
                else if(ch=='+'){
                     
                     result=result+sign*number;
                     sign=1;
                     number=0;
                }
                else if(ch=='-'){
                     result=result+sign*number;
                     sign=-1;
                     number=0;
                }
                else if(ch=='('){
                     st.push(result);
                     st.push(sign);
                     result=0;
                     sign=1;
                }
                else if(ch==')'){
                     
                     result=result+sign*number;

                     long long prevsign=st.top();
                     st.pop();
                     
                     long long prevres=st.top();
                     st.pop();

                     result=result+prevres*prevsign;
                     number=0;
                }
           }

           result=result+number*sign;


           return (int)result;
           
           
        }
};
