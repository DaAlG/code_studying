# dfs로는 불가능하대...
# bfs - queue 이용
from collections import deque

n = int(input()) # 테스트 케이스의 수

move = [(2,-1),(2,1),(1,-2),(1,2),(-1,-2),(-1,2),(-2,-1),(-2,1)] # 이동가능한 지점들
ans = 0

for i in range(n):
  l = int(input()) # l
  fx,fy = map(int, input().split()) # 시작점
  lx,ly = map(int,input().split())
  
  chess = [[0]*l for i in range(l)]
  visited = [[0]*l for i in range(l)]
  q = deque()
  q.append((fx,fy))

  while q:
    x,y  = q.popleft()

    if x==lx and y==ly:
      ans = chess[x][y]
      break

    for i in range(8):
      nx = x+ move[i][0]
      ny = y+ move[i][1]

      if nx>=0 and nx<l and ny>=0 and ny<l:
        if visited[nx][ny] == 0:
          chess[nx][ny] = chess[x][y]+1
          q.append((nx,ny))
          visited[nx][ny] = 1
  print(ans)