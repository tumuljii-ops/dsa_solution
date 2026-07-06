class Solution {
public:
    string multiply(string num1, string num2) {

          if(num1=="0" || num2=="0"){
              return "0";
          }
          
          int n=num1.size();
          int m=num2.size();

          vector<int>ans(n+m,0);

          for(int i=n-1;i>=0;i--){
              
              for(int j=m-1;j>=0;j--){
                  
                   int product=(num1[i]-'0')*(num2[j]-'0');

                   int carry=i+j;
                   int prod=i+j+1;

                   int sum=product+ans[prod];

                   ans[prod]=sum%10;
                   ans[carry]+=sum/10;
              }
          }

          int i=0;

          while(i<ans.size() && ans[i]==0){
               i++;
          }

          string result="";

          while(i<ans.size()){
               result+=ans[i]+'0';
               i++;
          }

          return result;
    }
};