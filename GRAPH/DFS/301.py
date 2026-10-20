class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        # Step 1: Calculate the exact number of misplaced '(' and ')' to remove
        left_rem = 0
        right_rem = 0
        for char in s:
            if char == '(':
                left_rem += 1
            elif char == ')':
                if left_rem > 0:
                    left_rem -= 1  # Matches an existing '('
                else:
                    right_rem += 1  # Unmatched ')'

        result_set = set()

        # Step 2: Define the DFS backtracking function
        def dfs(index, left_rem, right_rem, open_brackets, current):
            # Base case: reached the end of the string
            if index == len(s):
                if left_rem == 0 and right_rem == 0 and open_brackets == 0:
                    result_set.add(current)
                return

            c = s[index]

            # Choice 1: Remove the current character (if it's a parenthesis and we still need to remove it)
            if c == '(' and left_rem > 0:
                dfs(index + 1, left_rem - 1, right_rem, open_brackets, current)
            if c == ')' and right_rem > 0:
                dfs(index + 1, left_rem, right_rem - 1, open_brackets, current)

            # Choice 2: Keep the current character
            if c != '(' and c != ')':
                # Regular characters are always kept
                dfs(index + 1, left_rem, right_rem, open_brackets, current + c)
            elif c == '(':
                # Keep '(' and increase open count
                dfs(index + 1, left_rem, right_rem, open_brackets + 1, current + c)
            elif c == ')' and open_brackets > 0:
                # Keep ')' only if there's a matching '(' available
                dfs(index + 1, left_rem, right_rem, open_brackets - 1, current + c)

        # Step 3: Run DFS starting from index 0
        dfs(0, left_rem, right_rem, 0, "")

        # Step 4: Convert the set to a list and return
        return list(result_set)