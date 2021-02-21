def solution(n, lost, reserve):
    answer = 0
    
    data = [1 for i in range(0,n+1)] # 1~n까지 만들어줄거야
    data[0] = 0
    answer = n
    
    for i in reserve: #  여벌 옷 챙겨온 친구들
        data[i]+=1
    for i in lost: # 도난당한 친구들
        data[i]-=1
        if data[i] == 0: # 여벌&도난인 경우 빼기 위함
            answer -= 1

    for i in reserve:
        if data[i] > 1 :
            if i-1!=0 and data[i-1] == 0:
                data[i-1] += 1
                data[i] -= 1
                answer+=1
                continue
            elif i+1!=n+1 and data[i+1]==0:
                data[i+1]+=1
                data[i] -=1
                answer+=1
            
    return answer