# 시작점, 도착점까지 경로 수를 구하는 것이므로 도착점을 이용해서 문제를 푼다!! ㅠㅠ 어려워..
def dfs(x,y):
  global mapp, dx, dy, dp
  temp = 0
  if dp[x][y] != -1: # 이미 탐색했다면
    return dp[x][y]

  for i in range(4):

    nx = x + dx[i]
    ny = y + dy[i]
    
    if 0<=nx<m and 0<=ny<n and mapp[x][y] > mapp[nx][ny]:  
      # print(x,y,dp[x][y],i)
      temp += dfs(nx,ny) # 이 부분 어려웠음 # 목적지 값이 1이므로 목적지까지 도달한 경로 계속 더하기
      # print('*'*30)
    dp[x][y] = temp
  return dp[x][y]

m, n = map(int, input().split())
mapp = []
for i in range(m):
  mapp.append(list(map(int, input().split())))
# print(mapp)
dp = [[-1]*n for i in range(m)]
dp[m-1][n-1] = 1 # 최종 목적지
# 좌우상하 0123
dx = [-1,1,0,0]
dy = [0,0,-1,1]

print(dfs(0,0))
# print(dp)