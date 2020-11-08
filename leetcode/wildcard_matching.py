class Solution:
    @staticmethod
    def add_table(table, state, char, next_state):
        table_item = table.get(state, None)
        if table_item is None:
            table_item = table[state] = {}
        next_states = table_item.get(char, None)
        if next_states is None:
            next_states = table_item[char] = []
        next_states.append(next_state)

    @classmethod
    def create_table(cls, pattern):
        table = {}
        state = 0
        for char in pattern:
            if "a" <= char <= "z":
                cls.add_table(table, state, char, state + 1)
                state += 1
            elif char == "?":
                for i in range(26):
                    cls.add_table(table, state, chr(i + ord("a")), state + 1)
                state += 1
            elif char == "*":
                for i in range(26):
                    cls.add_table(table, state, chr(i + ord("a")), state)
            else:
                assert False
        return table, state

    def isMatch(self, s: str, p: str) -> bool:
        table, final_state = self.create_table(p)
        length = len(s)
        dp = {}

        def check(index, state):
            if index >= length:
                return state == final_state
            key = (index, state)
            if key in dp:
                return dp[key]

            char = s[index]
            table_item = table.get(state, None)
            if table_item is None:
                dp[key] = False
                return False
            next_states = table_item.get(char, None)
            if next_states is None:
                dp[key] = False
                return False
            for next_state in next_states:
                matched = check(index + 1, next_state)
                if matched:
                    dp[key] = True
                    return True
            dp[key] = False
            return False

        return check(0, 0)


if __name__ == "__main__":
    solution = Solution()
    matched = solution.isMatch("aa", "*")
    assert matched is True
    matched = solution.isMatch("adceb", "*a*b")
    assert matched is True
    matched = solution.isMatch("abefcdgiescdfimde", "ab*cd?i*de")
    assert matched is True
    matched = solution.isMatch(
        "abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab", "*aabb***aa**a******aa*"
    )
    matched = solution.isMatch(
        "bbbbabaabbabbababaabaabababaababaaaabaaabbbabbbbbbabbabbabbaaabaababbbababbbaaababbbbaabbaababbabababbbbbbabbbbbaabbabaababbabbbbbbaabbbabbbaabaaababaabaaaabababbababbaaabbaabaabaabbbbbbaabbaaaaaabbabb",
        "aa***bb*b**a***bb***b*b*ba********ba***bbbb*bba*a*b***ba*a*b**aabbba*aba****a*ba*****a*bab**a**b**b*a*",
    )
