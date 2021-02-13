def solution(numbers, hand):
    answer = ''
    L = [3,0] # *위치
    R = [3,2] # #위치
    for target in numbers:
        if target in [1,4,7]:
            answer += 'L'
            L = [(target-1)//3,0]
            
        elif target in [3,6,9]:
            answer += 'R'
            R = [(target-3)//3,2]
            
        elif target in [2,5,8,0]:
            if target != 0:
                T = [(target-2)//3,1]
            else:
                T = [3,1]
            
            ldis = abs(L[0]-T[0])+abs(L[1]-T[1])
            rdis = abs(R[0]-T[0])+abs(R[1]-T[1])
            
            if ldis<rdis: 
                answer += 'L'
                L = T
            elif ldis == rdis:
                if hand == 'right':
                    answer+= 'R'
                    R = T
                else:
                    answer += 'L'
                    L = T
            else:
                answer+= 'R'
                R = T
                    
    return answer