def solution(citations):
    answer = 0
    citations.sort(reverse = True)
    for c, citation in enumerate(citations):
        if citation <= c:
            answer = c
            break
            
        else :
            answer = len(citations)
    return answer