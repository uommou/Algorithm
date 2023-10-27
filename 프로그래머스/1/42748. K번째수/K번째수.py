def solution(array, commands):
    answer = []
    for c in range(len(commands)):
        command = commands[c]
        newarray = array[command[0] - 1:command[1]]
        newarray.sort()
        print(newarray)
        answer.append(newarray[command[2] - 1])
    return answer