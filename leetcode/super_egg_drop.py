class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        dp = [[j for j in range(N + 1)] for _ in range(K)]
        for i in range(1, K):
            for j in range(1, N + 1):
                low = 1
                high = j
                count = j
                while low < high:
                    mid = low + (high - low + 1) // 2
                    left = dp[i - 1][mid - 1]
                    right = dp[i][j - mid]
                    count = min(count, max(left, right) + 1)
                    if left == right:
                        break
                    elif left > right:
                        high = mid - 1
                    else:
                        low = mid
                dp[i][j] = count
        return dp[K - 1][N]


if __name__ == "__main__":
    solution = Solution()
    assert solution.superEggDrop(1, 2) == 2
    assert solution.superEggDrop(2, 3) == 2
    assert solution.superEggDrop(2, 6) == 3
    assert solution.superEggDrop(2, 2) == 2
    assert solution.superEggDrop(3, 14) == 4
    assert solution.superEggDrop(100, 8191) == 12
