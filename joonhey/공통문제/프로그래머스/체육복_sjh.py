#그리디
def solution(n,lost,reserve):
    u =  [1]*(n+2)
    #N
    for i in reserve:
        u[i]+=1
    #N
    for i in lost:
        u[i] -= 1
    #N
    for i in range(1,n+1): #N만큼 순회
        if u[i-1]==0 and u[i]==2:
            u[i-1:i+1] = [1,1]
        elif u[i+1]==0 and u[i]==2:
            u[i:i+2] = [1,1]
    #N
    return len([x for x in u[1:-1] if x>0])
