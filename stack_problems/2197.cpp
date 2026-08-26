#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::stack<long long> st;

        for (int num : nums) {
            long long curr = num;

            // Convergence check using stack
            while (!st.empty()) {
                long long topVal = st.top();
                long long g = std::gcd(curr, topVal);

                if (g > 1) {
                    st.pop(); // Remove top element
                    curr = (curr * topVal) / g; // Calculate LCM and update curr
                } else {
                    break; // Coprime reached, stop merging
                }
            }

            // Push the fully merged number onto the stack
            st.push(curr);
        }

        // Convert std::stack to std::vector for the result
        std::vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        std::reverse(result.begin(), result.end()); // Stack pops in reverse order

        return result;
    }
};