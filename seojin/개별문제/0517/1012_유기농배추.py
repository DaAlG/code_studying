from collections import deque
case = int(input())
res = []

for _ in range(case):
  m,n,k = map(int, input().split())
  graph  = [[0]*m for i in range(n)]
  for i in range(k):
    x,y = map(int,input().split())
    graph[y][x] = 1
  
  # print(graph)
  visited = [[0]*m for i in range(n)]
  # print(visited)
  dx = [-1,1,0,0]
  dy = [0,0,-1,1]
  queue = deque()
  answer = 0
  
  for i in range(n):
    for j in range(m):
      # print(i,j)
      if graph[i][j]==1 and visited[i][j]==0:
        visited[i][j] = 1
        queue.append((i,j))
        answer +=1
        # print('*'*30)
        while queue:
          x,y = queue.popleft()
          # print(x,y)
          for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if 0<=nx<n and 0<=ny<m and visited[nx][ny]==0 and graph[nx][ny]==1:
              queue.append((nx,ny))
              visited[nx][ny] = 1
        # print('*'*30)
    # print('saaa')
  # print(answer)
  res.append(answer)

for i in range(case):
  print(res[i])