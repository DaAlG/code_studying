from collections import deque

n,m = map(int,input().split())
graph = []
for i in range(n):
  graph.append(list(map(int,input())))

# print(graph)

queue = deque()
queue.append((0,0,1))

dx = [-1,1,0,0]
dy = [0,0,-1,1]

count = 0

while queue:
  x,y,day = queue.popleft()
  if x == n-1 and y == m-1:
    break

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if 0<=nx<n and 0<=ny<m:
      if graph[nx][ny]==1:
        queue.append((nx,ny,day+1))
        graph[nx][ny] = graph[x][y]+1
  # print(graph)
  
print(graph[n-1][m-1])
# print(count)

# print(graph)