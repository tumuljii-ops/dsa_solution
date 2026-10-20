class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        array = nums.copy()
        n = len(nums)
        nums = sorted(nums)
        sum_ans = 0

        def compute_lps(pattern):
            m = len(pattern)
            lps = [0] * m
            length = 0
            i = 1
            while i < m:
                if pattern[i] == pattern[length]:
                    length += 1
                    lps[i] = length
                    i += 1
                else:
                    if length != 0:
                        length = lps[length - 1]
                    else:
                        lps[i] = 0
                        i += 1
            return lps

        def kmp_search(text, pattern):
            t_len = len(text)
            p_len = len(pattern)
            if p_len == 0:
                return True
            lps = compute_lps(pattern)
            i = 0
            j = 0
            while i < t_len:
                if pattern[j] == text[i]:
                    i += 1
                    j += 1
                if j == p_len:
                    return True
                elif i < t_len and pattern[j] != text[i]:
                    if j != 0:
                        j = lps[j - 1]
                    else:
                        i += 1
            return False

        for i in range(1, n + 1):
            if n % i != 0:
                continue
            else:
                valid = True
                
                for j in range(0, n, i):
                    array1 = nums[j:j+i]
                    s = array[j:j+i]
                    array3 = s + s

                    if not kmp_search(array3, array1):
                        valid = False
                        break
                
                if valid:
                    sum_ans += i
        
        return sum_ans