class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        def best_for_pair(d1: str, d2: str) -> int:
            dist = 0
            used = 0
            best = 0

            for ch in s:
                if ch == d1 or ch == d2:
                    dist += 1
                elif used < k:
                    used += 1
                    dist += 1
                else:
                    dist -= 1

                if dist > best:
                    best = dist

            return best

        return max(
            best_for_pair("N", "E"),
            best_for_pair("N", "W"),
            best_for_pair("S", "E"),
            best_for_pair("S", "W"),
        )