from itertools import combinations
def solution(clothes):
    answer = 1
    wear_type = dict()
    
    for i,j in clothes:
        if j not in wear_type:
            wear_type[j] = 1
        else:
            wear_type[j] += 1
            
#     # print(wear_type)
#     for i in range(len(wear_type)): # 종류 개수만큼 조합 구해야돼
#         combi = list(combinations(wear_type,i+1))
        
#         for j in combi: # 그 조합에서 확인하기
#             temp = 1
#             for k in j: # 조합이 막 2개 이상이면 a*b 이렇게 곱해야함
#                 # print(k)
#                 temp*=wear_type[k]
#             # print('*'*30)
#             answer += temp

# 정답...
# 가능한 모든 조합을 직접 구해서 계산할 필요가 없습니다.
# 예를들어 머리:3, 얼굴:2, 옷:1 이라면 총 가능한 개수는

# (3+1) * (2+1)*(1+1) -1 = 13
# +1씩을 더한 것은 착용하지 않은 경우가 추가 되기 때문이고 마지막으로 -1을 한것은 모든 부위를 입지 않은 경우는 없기 때문입니다.
# 생각도 못했다....

    for i in wear_type:
        # print(i)
        answer *= (wear_type[i]+1) 
    
    answer -= 1
    
    return answer
