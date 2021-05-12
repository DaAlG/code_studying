# 경쟁적 전염 문제랑 유사해!!
import heapq

def tomato(day,x,y):
  global cnt0, cnt1,dx,dy,n,m,data
  day +=1
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
  
    if nx>=0 and nx<m and ny>=0 and ny<n:
      if data[nx][ny] == 0: 
        data[nx][ny] = 1
        heapq.heappush(q,(day,nx,ny))
        cnt1+=1 
        cnt0-=1

n,m = map(int,input().split())
cnt1 = 0
cnt0 = 0
cnt_1 = 0
data = []

for i in range(m):
  data.append(list(map(int,input().split())))
  cnt1 += data[i].count(1)
  cnt0 += data[i].count(0)
  cnt_1 += data[i].count(-1)
# print(cnt1,cnt0,cnt_1)

total = cnt0+cnt1

dx = [-1,1,0,0]
dy = [0,0,-1,1]

q = []
day = 0

if cnt0 == 0:
  print(0)
else:
  for i in range(m):
    for j in range(n):
      if data[i][j] == 1:
        # day를 같이 처리해줘야 몇 일만에 끝나는지 알 수 있음.
        heapq.heappush(q,(day,i,j))

  while q:
    day,x,y = heapq.heappop(q)
    # print(day,x,y)
    tomato(day, x,y)

  
  if cnt0 != 0: # 안 익은 토마토가 있다면
    print(-1)
  else:
    print(day)
  