def solution(numbers):
    answer = ''
    str_list = [str(i) for i in numbers]
    str_list.sort(key=lambda x:x*3, reverse = True)
    for num in str_list:
        answer = answer + num
        
    if answer[0] == '0':
        answer = '0'
    return answer