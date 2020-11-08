class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False] * (len(s) + 1) for _ in range(len(p) + 1)]
        dp[-1][-1] = True
        for p_index in range(len(p)):
            p_char = p[p_index]
            if p_index == len(p) - 1:
                p_next = ""
            else:
                p_next = p[p_index + 1]
                if p_next == "*":
                    dp[p_index + 1][-1] = dp[p_index - 1][-1]
            for s_index in range(len(s)):
                s_char = s[s_index]
                matched = False
                if p_next == "*":
                    if dp[p_index - 1][s_index]:
                        matched = True
                    elif p_char == "." or p_char == s_char:
                        matched = (
                            dp[p_index][s_index - 1] or dp[p_index - 1][s_index - 1]
                        )
                elif p_char == "*":
                    matched = dp[p_index - 2][s_index] or dp[p_index - 1][s_index]
                elif p_char == "." or p_char == s_char:
                    matched = dp[p_index - 1][s_index - 1]
                dp[p_index][s_index] = matched

        return dp[len(p) - 1][len(s) - 1]


if __name__ == "__main__":
    solution = Solution()
    assert solution.isMatch("aab", "c*a*b") is True
    assert solution.isMatch("aa", "a") is False
    assert solution.isMatch("mississippi", "mis*is*ip*.") is True
    assert solution.isMatch("abcd", "d*") is False
    assert solution.isMatch("", ".") is False
    assert solution.isMatch("", "c*c*") is True
