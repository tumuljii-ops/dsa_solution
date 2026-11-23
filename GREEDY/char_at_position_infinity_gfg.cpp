class Solution:

    def posInfinite(self, s: str, pos: int) -> str:
        curr_len = len(s)
        step = 1

        while curr_len < pos:
            curr_len = 2 * curr_len + step
            step += 1

        step -= 1
        while step > 0:
            prev_len = (curr_len - step) // 2

            if pos <= prev_len:
                curr_len = prev_len
            elif pos <= prev_len + step:
                return "$"
            else:
                pos = curr_len - pos + 1
                curr_len = prev_len

            step -= 1

        return s[pos - 1]