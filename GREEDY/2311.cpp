class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:

        power=0
        count=0

        current_val=0

        rev=s[::-1]

        for ch in rev:

            if ch=='0':
                power+=1
                count+=1
            else:

                add_val=1<<power

                if add_val+current_val<=k and add_val<=k:

                    current_val+=add_val
                    count+=1
                    power+=1
        
        return count




        