def solution(nums):
    answer = 0
    limit = len(nums)/2
    nums = set(nums)
    if len(nums) <= limit:
        answer = len(nums)
        
    else :
        answer = limit
    return answer