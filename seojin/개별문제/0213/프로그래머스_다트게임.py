def solution(dartResult):
    answer = 0
    score = [str(i) for i in range(0,11)]
    bonus = ['S','D','T']
    opt = ['*','#']
    temp = []
    
    nowi = -1 
    previ = -2
    now = 0
    
    for i in dartResult:
        if i in score:
            if now == 1 and i == '0': # 10일때 처리
                now = 10
            else:
                now = int(i)
        elif i in bonus:
            if i =='S':
                now **= 1
            elif i =='D':
                now **= 2
            else:
                now **=3
            temp.append(now)
            nowi += 1
            previ += 1
        elif i in opt:
            if i == '*':
                if nowi != 0:
                    temp[previ] *= 2
                temp[nowi] *= 2
            elif i == '#':
                temp[nowi] *= -1
    answer = sum(temp)
    return answer