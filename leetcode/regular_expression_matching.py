class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(s) == 0:
            return all(s[i : i + 2] == ".*" for i in range(len(s) // 2))
        if len(p) == 0:
            return False
        table = {(-1, -1): True}
        for i in range(len(s)):
            table[(i, -1)] = False
        for i, p_char in enumerate(p):
            table[(-1, i)] = table[(-1, i - 1)] and p_char == "*"
        for s_index in range(len(s)):
            s_char = s[s_index]
            for p_index in range(len(p)):
                p_char = p[p_index]
                if "a" <= p_char <= "z":
                    matched = s_char == p_char and table[(s_index - 1, p_index - 1)]
                elif p_char == ".":
                    matched = table[(s_index - 1, p_index - 1)]
                elif p_char == "*":
                    p_prefix = p[p_index - 1 : p_index]
                    if p_prefix != "." and p_prefix != s_char:
                        matched = table[(s_index - 1), (p_index - 1)]
                    else:
                        matched = (
                            table[(s_index - 1, p_index - 1)]
                            or table[(s_index - 1, p_index)]
                            or table[(s_index, p_index - 1)]
                        )
                else:
                    assert False
                table[(s_index, p_index)] = matched
        return table[(len(s) - 1, len(p) - 1)]


if __name__ == "__main__":
    solution = Solution()
    assert solution.isMatch("aab", "c*a*b") is True
