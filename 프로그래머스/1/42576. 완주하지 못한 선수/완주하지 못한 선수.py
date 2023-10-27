def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    for c in range(len(completion)):
        if participant[c]!=completion[c]:
            return participant[c]
    return participant[len(participant)-1]