def solution(numbers, target):
    answer = 0
    def dfs(index, total):
        if index == len(numbers):
            return 1 if total == target else 0
        return dfs(index + 1, total + numbers[index]) + dfs(index + 1, total - numbers[index])
    return dfs(0, 0)