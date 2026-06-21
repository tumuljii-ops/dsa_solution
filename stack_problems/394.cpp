class Solution {
public:
    bool isDigit(string s){

        return s=="0" || s=="1" || s=="2" || s=="3" || s=="4" ||
               s=="5" || s=="6" || s=="7" || s=="8" || s=="9";
    }

    string decodeString(string s) {

        stack<string> st;

        int n = s.length();

        for(int i=0;i<n;i++){

            if(s[i] == ']'){

                string ans1 = "";

                while(!st.empty() && st.top() != "["){

                    ans1 = st.top() + ans1;
                    st.pop();
                }

                st.pop(); // remove '['

                string numStr = "";

                while(!st.empty() && isDigit(st.top())){

                    numStr = st.top() + numStr;
                    st.pop();
                }

                int num = stoi(numStr);

                string expanded = "";

                while(num--){
                    expanded += ans1;
                }

                st.push(expanded);
            }
            else{

                st.push(string(1,s[i]));
            }
        }

        string ans = "";

        while(!st.empty()){

            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};