class Solution:

    mod = 10**9 + 7

    def smallestUniqueSubarray(self, nums: List[int]) -> int:

        def possible(mid, base, nums, power, mod):

            map = {}

            hash = 0

            left = 0
            right = 0

            while right < len(nums):

                hash = (hash * base + nums[right]) % mod

                if right - left + 1 < mid:
                    right += 1
                else:

                    if hash not in map:
                        map[hash] = 1
                    else:
                        map[hash] += 1

                    hash = (hash - power * nums[left]) % mod
                    left += 1
                    right += 1

            for key in map.keys():

                if map[key] == 1:
                    return True

            return False

        maxi = max(nums)
        base = maxi + 1
        mod = Solution.mod
        n = len(nums)

        low = 1
        high = n
        num = -1

        while low <= high:

            mid = (low + high) // 2

            power = pow(base, mid - 1, mod)

            if possible(mid, base, nums, power, mod) == True:
                num = mid
                high = mid - 1
            else:
                low = mid + 1

        return num