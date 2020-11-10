class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        def search(k, n):
            if k == 1:
                return n
            count = dp.get((k, n), None)
            if count is not None:
                return count
            low = 1
            high = n
            count = n
            while low < high:
                mid = low + (high - low) // 2
                left = search(k - 1, mid - 1)
                right = search(k, n - mid)
                current = (left if left >= right else right) + 1
                count = current if current < count else count
                if left == right:
                    break
                elif left > right:
                    high = mid
                else:
                    low = mid + 1
            dp[(k, n)] = count
            return count

        dp = {}

        return search(K, N)


if __name__ == "__main__":
    solution = Solution()
    assert solution.superEggDrop(1, 2) == 2
    assert solution.superEggDrop(2, 3) == 2
    assert solution.superEggDrop(2, 6) == 3
    assert solution.superEggDrop(2, 2) == 2
    assert solution.superEggDrop(3, 14) == 4
    assert solution.superEggDrop(3, 25) == 5
    assert solution.superEggDrop(100, 8191) == 13
