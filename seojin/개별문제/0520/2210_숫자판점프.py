from collections import deque
import copy
graph = []
for i in range(5):
  graph.append(list(input().split()))

q = deque()
answer = []
dx = [-1,1,0,0]
dy = [0,0,-1,1]

for i in range(5):
  for j in range(5):
    now = graph[i][j]
    q.append((i,j,now))

    while q:
      x,y,now = q.popleft()
    
      if len(now) == 6:
        if now not in answer:
          # print(answer)
          answer.append(now)
          continue
        else:
          continue

      for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]

        if 0<=nx<5 and 0<=ny<5:
          temp = copy.deepcopy(now)
          now += graph[nx][ny]
          q.append((nx,ny,now))
          now = temp

print(len(answer))