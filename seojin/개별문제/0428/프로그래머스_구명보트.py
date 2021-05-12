import math
def solution(people, limit):
    answer = 0
    cnt = len(people) # 사람 수
    first = 0
    second = cnt-1
    
    people.sort(reverse=True)

    while(first<=second):
        if people[first]+people[second]<=limit:
            answer+=1
            first+=1
            second-=1
        else:
            first+=1
            answer+=1
    
    return answer