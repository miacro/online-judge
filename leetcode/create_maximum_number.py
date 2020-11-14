from typing import List


class Solution:
    def select(self, index, count, nums, table):
        if count == 0:
            return []
        elif len(nums) - index < count:
            return []
        selected = table.get((index, count), None)
        if selected is not None:
            return selected
        selected = self.select(index + 1, count, nums, table)
        if len(selected) < count or selected[0] <= nums[index]:
            selected_o = self.select(index + 1, count - 1, nums, table)
            if len(selected_o) == count - 1:
                selected = [nums[index]] + selected_o
        table[(index, count)] = selected
        return selected

    def compare(self, list1, list2):
        for a, b in zip(list1, list2):
            if a > b:
                return list1
            elif a < b:
                return list2
        return list1

    def merge(self, list1, list2):
        index1, index2 = 0, 0
        merged = []
        while True:
            if index2 >= len(list2):
                merged += list1[index1:]
                break
            elif index1 >= len(list1):
                merged += list2[index2:]
                break
            a, b = list1[index1], list2[index2]
            if a > b:
                merged.append(a)
                index1 += 1
                continue
            elif a < b:
                merged.append(b)
                index2 += 1
                continue
            if index1 >= len(list1) - 1:
                pick = 2
            elif index2 >= len(list2) - 1:
                pick = 1
            elif a > list1[index1 + 1] and a > list2[index2 + 1]:
                pick = 1
            elif list1[index1 + 1] >= list2[index2 + 1]:
                pick = 1
            else:
                pick = 2
            merged.append(a)
            if pick == 1:
                index1 += 1
            else:
                index2 += 1

        return merged

    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        table1 = {}
        table2 = {}
        result = None
        for i in range(k + 1):
            selected1 = self.select(0, i, nums1, table1)
            if len(selected1) != i:
                continue
            selected2 = self.select(0, k - i, nums2, table2)
            if len(selected2) != k - i:
                continue
            merged = self.merge(selected1, selected2)
            if result is not None:
                result = self.compare(merged, result)
            else:
                result = merged
        return result


if __name__ == "__main__":
    solution = Solution()
    assert solution.maxNumber([3, 4, 6, 5], [9, 1, 2, 5, 8, 3], 5) == [9, 8, 6, 5, 3]
    assert solution.maxNumber([5, 5, 1], [4, 0, 1], 3) == [5, 5, 4]
    input1 = [2, 5, 6, 4, 4, 0]
    input2 = [7, 3, 8, 0, 6, 5, 7, 6, 2]
    select = 15
    formal = [7, 3, 8, 2, 5, 6, 4, 4, 0, 6, 5, 7, 6, 2, 0]
    assert solution.maxNumber(input1, input2, select) == formal
    input1 = [1, 6, 5, 4, 7, 3, 9, 5, 3, 7, 8, 4, 1, 1, 4]
    input2 = [4, 3, 1, 3, 5, 9]
    select = 21
    formal = [4, 3, 1, 6, 5, 4, 7, 3, 9, 5, 3, 7, 8, 4, 1, 3, 5, 9, 1, 1, 4]
    assert solution.maxNumber(input1, input2, select) == formal
    input1 = [2, 1, 7, 8, 0, 1, 7, 3, 5, 8, 9, 0, 0, 7, 0, 2, 2, 7, 3, 5, 5]
    input2 = [2, 6, 2, 0, 1, 0, 5, 4, 5, 5, 3, 3, 3, 4]
    select = 35
    formal = (
        [2, 6, 2, 2, 1, 7, 8, 0, 1, 7, 3, 5, 8, 9, 0, 1]
        + [0, 5, 4, 5, 5, 3, 3, 3, 4, 0, 0, 7, 0]
        + [2, 2, 7, 3, 5, 5]
    )
    assert solution.maxNumber(input1, input2, select) == formal
    input1 = [5, 0, 2, 1, 0, 1, 0, 3, 9, 1, 2, 8, 0, 9, 8, 1, 4, 7, 3]
    input2 = [7, 6, 7, 1, 0, 1, 0, 5, 6, 0, 5, 0]
    select = 31
    formal = (
        [7, 6, 7, 5, 1, 0, 2, 1, 0, 1, 0, 5, 6, 0]
        + [5, 0, 1, 0, 3, 9, 1, 2, 8, 0, 9, 8]
        + [1, 4, 7, 3, 0]
    )
    assert solution.maxNumber(input1, input2, select) == formal
