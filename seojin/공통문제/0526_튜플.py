def solution(s):
    answer = []
    temp = []
    cnt = 0
    for i in range(1,len(s)-1):
        if s[i] == '{':
            start = i
        elif s[i] == '}':
            temp.append(s[start+1:i])
    for i in range(len(temp)):
        temp[i] = temp[i].split(',')
    temp.sort(key=len)

    for i in temp:
        for j in i:
            if int(j) not in answer:
                answer.append(int(j))
    return answer
