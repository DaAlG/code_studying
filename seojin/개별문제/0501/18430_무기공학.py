# 너무 복잡해...알고싶지않다.....
def rightUp(y,x):
  global namu
  return namu[y][x-1]+namu[y+1][x]+2*namu[y][x]

def rightDown(y,x):
  global namu
  return namu[y][x-1]+namu[y-1][x]+2*namu[y][x]

def leftUp(y,x):
  global namu
  return namu[y][x+1]+namu[y+1][x]+2*namu[y][x]

def leftDown(y,x):
  global namu
  return namu[y][x+1]+namu[y-1][x]+2*namu[y][x]

ans = 0
def dfs(y, x, sum): 
  global n, m, visited, ans
  if x == m:
    x = 0
    y+=1
  if y == n:
    ans = max(ans,sum)
    return
  if visited[y][x]!=1:
    if (y+1<n) and (x-1>=0) and (visited[y+1][x]!=1) and (visited[y][x-1]!=1): # 경우 1(ㄱ 모양)
      visited[y][x] = 1
      visited[y+1][x] = 1
      visited[y][x-1] = 1
      nsum = sum+rightUp(y,x);
      dfs(y,x+1,nsum)
      # 끝까지 갔다왔으면 다시 되돌려놔야함
      visited[y][x] = 0 
      visited[y+1][x] = 0
      visited[y][x-1] = 0
    if (y-1>=0) and (x-1>=0) and (visited[y-1][x]!=1) and (visited[y][x-1]!=1): # 경우 2(ㄴ 뒤집은 모양)
      visited[y][x] = 1
      visited[y-1][x] = 1
      visited[y][x-1] = 1
      nsum = sum+rightDown(y,x);
      dfs(y,x+1,nsum)
      # 끝까지 갔다왔으면 다시 되돌려놔야함
      visited[y][x] = 0 
      visited[y-1][x] = 0
      visited[y][x-1] = 0
    if (y+1<n) and (x+1<m) and (visited[y+1][x]!=1) and (visited[y][x+1]!=1): # 경우 3(ㄱ 뒤집은 모양)
      visited[y][x] = 1
      visited[y+1][x] = 1
      visited[y][x+1] = 1
      nsum = sum+leftUp(y,x);
      dfs(y,x+1,nsum)
      # 끝까지 갔다왔으면 다시 되돌려놔야함
      visited[y][x] = 0 
      visited[y+1][x] = 0
      visited[y][x+1] = 0
    if (y-1>=0) and (x+1<m) and (visited[y-1][x]!=1) and (visited[y][x+1]!=1): # 경우 3(ㄱ 뒤집은 모양)
      visited[y][x] = 1
      visited[y-1][x] = 1
      visited[y][x+1] = 1
      nsum = sum+leftDown(y,x);
      dfs(y,x+1,nsum)
      # 끝까지 갔다왔으면 다시 되돌려놔야함
      visited[y][x] = 0 
      visited[y-1][x] = 0
      visited[y][x+1] = 0
  dfs(y,x+1,sum)

n, m = map(int, input().split())
namu = []
for i in range(n):
  namu.append(list(map(int, input().split())))
visited = [[0]*m for i in range(n)]

dfs(0,0,0)
print(ans)