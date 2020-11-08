class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        def calculate(start1, start2):
            if start1 == len1:
                return len2 - start2
            elif start2 == len2:
                return len1 - start1
            distance = table[start1][start2]
            if distance is not None:
                return distance
            elif word1[start1] == word2[start2]:
                distance = calculate(start1 + 1, start2 + 1)
            else:
                distance = min(
                    calculate(start1 + 1, start2),
                    calculate(start1, start2 + 1),
                    calculate(start1 + 1, start2 + 1),
                )
                distance += 1
            table[start1][start2] = distance
            return distance

        len1 = len(word1)
        len2 = len(word2)
        table = [[None for _ in range(len2)] for _ in range(len1)]
        return calculate(0, 0)


if __name__ == "__main__":
    solution = Solution()
    min_distance = solution.minDistance("rad", "apple")
    assert min_distance == 5
    min_distance = solution.minDistance(
        "trinitrophenylmethylnitramine", "dinitrophenylhydrazine"
    )
    assert min_distance == 10
