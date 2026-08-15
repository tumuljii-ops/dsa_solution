#include <bits/stdc++.h>
using namespace std;

int main(){
     // Fast I/O to avoid time limit issues
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     int t;
     cin >> t;

     while(t--){
        string s;
        cin >> s;

        int n = s.length();

        // 1. Base cases handled quickly
        if(n == 0){
            cout << 0 << '\n';
            continue;
        }
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }

        // 2. Count total number of '1's and '0's (Your logic)
        int count_1 = 0;
        int count_0 = 0;

        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                count_1++;
            }
            else{
                count_0++;
            }
        }

        // 3. Process the entire string using your greedy check
        int deletions = 0;
        
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                // To match a '1' at index j, we MUST use an available '0'
                if(count_0 > 0) {
                    count_0--;
                } else {
                    // No '0's left to neutralize this '1'. Game over!
                    deletions = n - j;
                    break;
                }
            }
            else {
                // To match a '0' at index j, we MUST use an available '1'
                if(count_1 > 0) {
                    count_1--;
                } else {
                    // No '1's left to neutralize this '0'. Game over!
                    deletions = n - j;
                    break;
                }
            }
        }
        
        cout << deletions << '\n';
     }

     return 0;
}
