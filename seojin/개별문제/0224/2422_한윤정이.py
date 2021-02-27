# 모르겟는데?????
# 일단 그냥 메모리/시간초과고 머고 그냥 답내볼까
from itertools import combinations
import copy
import sys

input = sys.stdin.readline

n,m = map(int,input().split())
hate = [] # 싫은 조합
for i in range(m):
  a,b = map(int,input().split())
  hate.append([a,b])
# print(hate) # hate 조합

data = [i for i in range(1,n+1)]
icecream = list(combinations(data,3))
# print(icecream) # icecream 조합
result = len(icecream)

entire = dict()
for i in icecream:
  i = map(str,i)
  i = ''.join(i)
  entire[i] = 0
# print(entire)

# 시간초과
# flag = 0
# for ice in icecream: # 260만개..
#   for h in hate: # 1만개.. # 이러면 260억...
#     if flag == 1:
#       flag = 0
#       break
#     a,b = h
#     if a in ice:
#       if b in ice:
#         print('I hate this', end=' ')
#         print(ice)
#         result-=1
#         flag = 1

# 메모리초과
stack = dict()
for i in hate: # 1만개..
  # temp = copy.deepcopy(data) # 이게 문제이려나?
  # # print(i[0],i[1])
  # # print(temp)
  # temp.remove(i[0])
  # temp.remove(i[1])
  # for j in temp: #198개
  #   a = list(i)
  #   a.append(j)
  #   a.sort()
  #   if a not in stack:
  #     stack.append(a)

  for j in data: # 200개..
    if j == i[0] or j==i[1]:
      continue
    # a = list(i)
    a = copy.deepcopy(i)
    a.append(j)
    a.sort()
    a = map(str,a)
    a = ''.join(a)
    if entire[a]==0: # 아니면 여기 탐색 때문에 시간이걸리나? 흠...ㅇ
      entire[a] = 1
print(entire,end=' ')
print(result-sum(list(entire.values())))


# print(result)
  