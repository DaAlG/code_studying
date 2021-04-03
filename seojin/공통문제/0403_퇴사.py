# from collections import deque
# N = int(input())
# T=[]
# P=[]
# for i in range(N):
#   a,b = map(int, input().split())
#   T.append(a)
#   P.append(b)
# result = 0

# def check(tar,cost):
#   global T,P,q
#   global result

#   flag = 0

#   for i in range(tar-1,-1,-1):
#     if tar == i+T[i]:
#       temp = max(cost+P[i],result)
#       q.append((i,temp))
#       result = temp
#       flag = 1

#   if flag == 0:
#     result = max(result, cost)
#   print(q)
# q = deque()

# # 마지막 날 상담일이 하루라면
# if T[N-1] == 1:
#   q.append((N-1,P[N-1]))
# else:
#   q.append((N-1,0))

# while q:
#   tar, cost = q.popleft()
#   print(tar)
#   check(tar, cost)
#   print('*'*30)
#   # print(q)
  

# # 이제 남은 애들 보면서 최대 cost 찾기

# print(result)


n = int(input())
t = []
p = []
dp = [0]*(n+1)
max_value = 0

for _ in range(n):
  x,y = map(int, input().split())
  t.append(x)
  p.append(y)

for i in range(n-1,-1,-1):
  time = i+t[i]

  #상담이 기간 안에 끝나는 경우
  if time <= n:
    dp[i] = max(p[i]+dp[time], max_value)
    max_value = dp[i]
  else:
    dp[i] = max_value
  # print(dp)
print(max_value)


# 원래 큐를 이용해서 풀었었는데 아닌 test case 3,4에서 아닌 것 같다는 느낌을 받았음....