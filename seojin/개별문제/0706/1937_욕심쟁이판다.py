# dynamic programming
# 방문한 좌표에 대해서는 더 이상 방문하지 않는다.
# 한 번 방문하면 그 위치에서 제일 오래 사는 days가 나오기 때문에 다시 탐색할 필요가 없는 것.
import sys
input = sys.stdin.readline

def dfs(x,y):
  global dx,dy,bamboo,dp

  if dp[x][y] != 0: # 방문한 적이 있다면
    return dp[x][y]
  dp[x][y] = 1 # 현재 위치도 방문한 거로 침

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if 0<=nx<n and 0<=ny<n:
      if bamboo[x][y] < bamboo[nx][ny]:
        dp[x][y] = max(dp[x][y], dfs(nx,ny)+1)
  return dp[x][y]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

n = int(input())
bamboo = []
for i in range(n):
  bamboo.append(list(map(int, input().split())))
dp = [[0 for i in range(n)] for i in range(n)]

ans = 0
for i in range(n):
  for j in range(n):
    ans = max(ans, dfs(i,j))

print(ans)