from collections import deque
n,m = map(int, input().split())
maze = [[] for i in range(n)]
for i in range(n):
  maze[i] = list(input())

# print(maze)

queue = deque()
dx = [-1,1,0,0]
dy = [0,0,-1,1]
answer = 0

for i in range(n):
  for j in range(m):
    visited = [[0]*m for i in range(n)]
    cnt = 0
    if maze[i][j] == 'L' and visited[i][j] != 1:
      print('*'*30)
      queue.append((i,j,cnt))
      print(i,j,cnt)
      visited[i][j] = 1
      while queue:
        x,y,cnt = queue.popleft()
        print(x,y,cnt)
        
        for k in range(4):
          nx = x+dx[k]
          ny = y+dy[k]
          
          if 0<=nx<n and 0<=ny<m and visited[nx][ny]!=1 and maze[nx][ny]=='L':
            cnt += 1
            queue.append((nx,ny,cnt))
            visited[nx][ny] = 1
            cnt -=1
    answer = max(cnt, answer)

print(answer)