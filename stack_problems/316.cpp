class Solution {
public:
    string removeDuplicateLetters(string s) {
            
             unordered_map<char,int> mpp;

             for(int i = 0; i < s.length(); i++){
                    mpp[s[i]]++;
             }

             stack<char> st;
             vector<bool> freq(26, false);

             for(int i = 0; i < s.length(); i++){

                   mpp[s[i]]--;

                   if(freq[s[i] - 'a']) {
                       continue;
                   }

                   while(!st.empty() && s[i] < st.top() && mpp[st.top()] > 0){
                            freq[st.top() - 'a'] = false;
                            st.pop();
                   }
                 
                   st.push(s[i]);
                   freq[s[i] - 'a'] = true;
             }

             string ans = "";

             while(!st.empty()){
                 ans += st.top();
                 st.pop();
             }

             reverse(ans.begin(), ans.end());

             return ans;
    }
};