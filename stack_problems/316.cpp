class Solution {
public:
    string removeDuplicateLetters(string s) {
            
             unordered_map<char,int> mpp;

             // Step 1: Count total frequency of each character
             for(int i = 0; i < s.length(); i++){
                    mpp[s[i]]++;
             }

             stack<char> st;
             vector<bool> freq(26, false);

             for(int i = 0; i < s.length(); i++){

                   // Decrement remaining count of s[i] in the rest of the string
                   mpp[s[i]]--;

                   // If s[i] is already included in our stack, skip it
                   if(freq[s[i] - 'a']) {
                       continue;
                   }

                   // Pop top element if it is lexicographically larger AND appears again later
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