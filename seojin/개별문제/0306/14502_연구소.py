# 전체 다 보는데, dfs/bfs이용한다는 아이디어는 캐치했는데
# 구현할 능력 부족 ~

import sys
input = sys.stdin.readline

n, m = map(int,input().split())
data = [] # 초기 맵 리스트
temp = [[0]*m for _ in range(n)] # 벽 설치한 뒤의 맵 리스트

for _ in range(n):
  data.append(list(map(int, input().split())))

dx = [-1,0,1,0]
dy = [0,1,0,-1]

result = 0

def virus(x,y): # 바이러스 사방으로 퍼지도록 하기
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if nx>=0 and nx<n and ny>=0 and ny<m:
      if temp[nx][ny] == 0:
        # 해당 위치에 바이러스 배치하고, 다시 재귀적으로 수행
         temp[nx][ny] = 2
         virus(nx,ny)

def get_score(): # 안전구역 체크하기
  score = 0
  
  for i in range(n):
    for j in range(m):
      if temp[i][j] == 0:
        score += 1
  
  return score

def dfs(count):
  global result

  # 울타리가 3개 설치된 경우
  # 바이러스 전파 확인할 temp 리스트에 복사해넣기
  if count == 3:
    for i in range(n):
      for j in range(m):
        temp[i][j] = data[i][j]
    
    # 각 바이러스 위치에서 전파 진행
    for i in range(n):
      for j in range(m):
        if temp[i][j] == 2:
          virus(i,j)
    result = max(result, get_score())
    return
  # 빈 공간에 울타리 설치
  for i in range(n):
    for j in range(m):
      if data[i][j] == 0:
        data[i][j] = 1
        count+= 1
        dfs(count)
        data[i][j] = 0
        count -= 1

dfs(0)
print(result)