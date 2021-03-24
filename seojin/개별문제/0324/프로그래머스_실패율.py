def solution(N, stages):
    answer = []
    people = len(stages)

    for i in range(1,N+1):
        count = stages.count(i) # i번째 stage에 있는 사람 수를 알 수 있어.
        
        if people == 0:
            fail = 0
        else:
            fail = count / people
        
        answer.append((-fail,i)) # - 붙여서 넣으면 큰 수가 앞쪽으로 가서 내림차순 구현 가능!
        people -= count
        
    answer.sort()
    answer = [i[1] for i in answer]  # answer의 두번째 원소만 가져올게(stage 번호)
    return answer
