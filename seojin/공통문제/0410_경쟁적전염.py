import heapq
import sys
import copy

input = sys.stdin.readline

n, k = map(int,input().split())
data = []*n
for i in range(n):
  data.append(list(map(int,input().split())))
s,resultx,resulty = map(int,input().split())

dx = [-1,0,1,0]
dy = [0,-1,0,1]

def virus(x,y,number):
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if nx>=0 and nx<n and ny>=0 and ny<n:
      if data[nx][ny] == 0:
        data[nx][ny] = number
        heapq.heappush(q,(number,nx*n+ny))
# 우선순위큐에서 튜플을 넣는다면, 우선순위를 줄 기준이 되는 데이터를 앞에 넣는다.

q = []
for i in range(n):
  for j in range(n):
    if data[i][j]!=0:
      heapq.heappush(q,(data[i][j], i*n+j)) # 바이러스이면 우선순위큐에 넣기

for i in range(1, s+1): # s초동안
  copyq = copy.deepcopy(q)
  # print(str(i)+'초에 큐는 ',end=' ')
  # print(copyq)
  # for i in range(n):
  #   print(data[i])
  # print('-'*10)
  q = [] # q를 비워버리면 이제 새로 이동하는 애들 구간만 보면 되니까 더 적게 봐도 되지 않을까 했는데,,! 아닌가봐
  while copyq:
    number, idx= heapq.heappop(copyq)
    x = idx//n
    y = idx%n
    virus(x,y,number)


print(data[resultx-1][resulty-1])