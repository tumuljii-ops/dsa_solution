class Solution {
public:
   /* int number(string ans){
        int result = 0;
        for(int i = 0; i < ans.length(); i++){
            result = result * 10 + (ans[i] - '0');
        }
        return result;
    }
    */

    string multiply(string num1, string num2) {
        //int number1 = number(num1);
       // int number2 = number(num2);
        // return to_string(number1 * number2);
        int n=num1.size();
        int m=num2.size();
        vector<int>ans(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                  int mul=(num1[i]-'0')*(num2[j]-'0');
                  int sum=mul+ans[i+j+1];
                  ans[i+j+1]=sum%10;
                  ans[i+j]+=sum/10;
            }
        }

      string result = "";
    bool leadingZero = true;

    for(int num : ans) {
        if(leadingZero && num == 0) continue;
        leadingZero = false;
        result.push_back(num + '0');
    }

    return result.empty() ? "0" : result;
        
    

    }
};