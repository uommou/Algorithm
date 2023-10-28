def solution(n, computers):
    def dfs(start):
        visited[start] = True;
        for i in range(n):
            if computers[start][i] == 1 and not visited[i]:
                dfs(i)
    visited = [False] * n
    answer =0
    for i in range(n):
        if not visited[i]:
            dfs(i)
            answer += 1
    return answer