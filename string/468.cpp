class Solution {
public:
    string validIPAddress(string queryIP) {
        int n1 = queryIP.length();

        bool ipv4 = true;
        int count = 0;
        int segmentCount = 0;
        int i = 0;

        while (i < n1) {
            string ans = "";
            while (i < n1 && queryIP[i] != '.') {
                ans += queryIP[i];
                i++;
            }

            if (i < n1 && queryIP[i] == '.') {
                count++;
                i++; 
            }

            segmentCount++;

            if (ans.length() == 0 || ans.length() > 3) {
                ipv4 = false;
                break;
            }

            for (char c : ans) {
                if (!isdigit(c)) {
                    ipv4 = false;
                    break;
                }
            }
            if (!ipv4) break;

            if (ans[0] == '0' && ans.length() > 1) {
                ipv4 = false;
                break;
            }

            if (stoi(ans) > 255) {
                ipv4 = false;
                break;
            }
        }

        if (count != 3 || segmentCount != 4) {
            ipv4 = false;
        }

 
        bool ipv6 = true;
        int count1 = 0;
        int segmentCount1 = 0;
        int j = 0;

        while (j < n1) {
            string ans = "";
            while (j < n1 && queryIP[j] != ':') {
                ans += queryIP[j];
                j++;
            }

            if (j < n1 && queryIP[j] == ':') {
                count1++;
                j++; 
            }

            segmentCount1++;

            if (ans.length() == 0 || ans.length() > 4) {
                ipv6 = false;
                break;
            }

            for (char ch : ans) {
                if (!isxdigit(ch)) {
                    ipv6 = false;
                    break;
                }
            }
            if (!ipv6) break;
        }

        if (count1 != 7 || segmentCount1 != 8) {
            ipv6 = false;
        }

        if (ipv4) return "IPv4";
        if (ipv6) return "IPv6";
        return "Neither";
    }
};