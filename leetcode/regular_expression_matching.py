class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        table = {(-1, -1): True}
        for p_index in range(len(p)):
            p_char = p[p_index]
            if p_index == len(p) - 1:
                p_next = ""
            else:
                p_next = p[p_index + 1]
            if p_next == "*":
                table[(p_index + 1, -1)] = table.get((p_index - 1, -1), False)
            for s_index in range(len(s)):
                s_char = s[s_index]
                matched = False
                if p_next == "*":
                    if table.get((p_index - 1, s_index), False):
                        matched = True
                    elif p_char == "." or p_char == s_char:
                        matched = table.get((p_index, s_index - 1), False) or table.get(
                            (p_index - 1, s_index - 1), False
                        )
                elif p_char == "*":
                    matched = table.get((p_index - 2, s_index), False) or table.get(
                        (p_index - 1, s_index), False
                    )
                elif p_char == "." or p_char == s_char:
                    matched = table.get((p_index - 1, s_index - 1), False)
                table[(p_index, s_index)] = matched

        return table.get((len(p) - 1, len(s) - 1), False)


if __name__ == "__main__":
    solution = Solution()
    assert solution.isMatch("aab", "c*a*b") is True
    assert solution.isMatch("aa", "a") is False
    assert solution.isMatch("mississippi", "mis*is*ip*.") is True
    assert solution.isMatch("abcd", "d*") is False
    assert solution.isMatch("", ".") is False
    assert solution.isMatch("", "c*c*") is True
